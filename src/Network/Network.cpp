#include "Network.hpp"

namespace network
{

Network::Network()
{
    //TODO stub
}

Network::~Network()
{
    //TODO stub
}

bool Network::initialize(configuration::ConfigurationManager& settings)
{

    firstFrame = true;
    // Check if the necessary variables are available
    bool hasSelector  = settings.hasBool("runFromFile");
    if (!hasSelector) {
        LOG("Network Error", "Boolean \"runFromFile\" undefined in config file.");
        return false;
    } else {
        runFromFile = settings.getBool("runFromFile");
    }

    bool hasFilePaths = settings.hasStringSeq("videoFilePaths");
    bool hasCamPaths  = settings.hasStringSeq("cameraPaths");

    bool hasValidSettings = (runFromFile && hasFilePaths) || (!runFromFile && hasCamPaths);

    if(!hasValidSettings) {
        LOG("Network Error", "std::vector<std::string> \"videoFilePaths\" or \"cameraPaths\" undefined in config file.");
        return false;
    }


    std::vector<std::string> filePaths, cameraPaths;
    filePaths = settings.getStringSeq("videoFilePaths");
    if (runFromFile) {
        filePaths = settings.getStringSeq("videoFilePaths");
    } else {
        cameraPaths = settings.getStringSeq("cameraPaths");
    }

    if (runFromFile) {
        return loadVideoFiles(settings, filePaths);
    } else {
        return initNetworkCameras(settings, cameraPaths);
    }

    nwam = new QNetworkAccessManager;
    serverUrl = "http://walla.walla.com/walla";
}


bool Network::initNetworkCameras(configuration::ConfigurationManager& settings,
                                 std::vector<std::string> cameraPaths)
{
    for (unsigned int i = 0; i < cameraPaths.size(); i++) {
        cv::VideoCapture cam(cameraPaths[i]);
        if (cam.isOpened()) {
            streams.push_back(cam);
        } else {
        LOG("Network Warning", "Error opening camera stream at: " << cameraPaths[i]);
        }
    }

    if (streams.size() > 0) {
        settings.setInt("nCameras", (int)streams.size());
        return true;
    } else {
        LOG("Network Error", "No camera streams from file(s)!");
        return false;
    }
}

bool Network::loadVideoFiles(configuration::ConfigurationManager& settings,
                             std::vector<std::string> filePaths)
{
    for (unsigned int i = 0; i < filePaths.size(); i++) {
        cv::VideoCapture cam(filePaths[i]);
        if (cam.isOpened()) {
            streams.push_back(cam);
        } else {
            LOG("Network Warning", "Error reading video file: " << filePaths[i]);
        }
    }
    if (streams.size() > 0) {
        settings.setInt("nCameras", (int)streams.size());
        return true;
    } else {
        LOG("Network Error", "No camera streams from network!");
        return false;
    }
}


void Network::reset()
{
    streams.clear();
}

Frame* Network::dequeFrame()
{
    if (runFromFile) { // Loading from file
        return getFileFrame();
    } else {
        return getNetworkCamFrame();
    }
}

void Network::broadcastData(Frame *frame)
{
    QNetworkRequest request(QUrl("http://walla.walla.com/walla"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"someTexts");

    QByteArray data;
    QUrlQuery params;

    params.addQueryItem("userid","user");
    params.addQueryItem("apiKey","key");
    QString walla(params.query());
    data = QByteArray(walla.toStdString().c_str());

    QNetworkReply *reply = nwam->post(request,data);
    return;

}

bool Network::initKinects(int nDevices)
{
    //TODO stub
}

Frame *Network::getFileFrame()
{
    Frame* frame = new Frame();
    bool success = true;

    for (unsigned int i = 0; i != streams.size(); i++) {
        CameraObject cam;
        cv::Mat rawImage;
        // Grab and retrieve image
        success = streams[i].grab() && streams[i].retrieve(rawImage);
        if (success)
        {
            cam.setRoomID(std::to_string(i));
            cam.addImage("rawImage", rawImage);
            frame->addCamera(cam);
            frame->setMomentaryFps(streams[i].get(CV_CAP_PROP_FPS));
        } else {
            LOG("Network Error", "Error retrieving frame from video file " << std::to_string(i) << ".");
            return 0;
        }
    }
    frame->initRoomPopulations(frame->getCameras());
    return frame;
}

Frame *Network::getNetworkCamFrame()
{
    Frame* frame = new Frame();
    bool success = true;

    for (unsigned int i = 0; i != streams.size(); i++) {
        streams[i].grab();
    }
    // Retrieve all images
    for (unsigned int i = 0; i != streams.size(); i++) {
        CameraObject cam;
        cv::Mat rawImage;
        success = streams[i].retrieve(rawImage);
        if(success) {
            cam.setRoomID(std::to_string(i));
            cam.addImage("rawImage", rawImage);
            frame->addCamera(cam);
            if (firstFrame) {
                frame->setMomentaryFps(0);
                firstFrame = false;
            } else {
                frame->setMomentaryFps(1.0/timer.getSeconds());
            }
            timer.reset();
        } else {
            LOG("Network Error", "Error retrieving frame from camera " << std::to_string(i) << ".");
            return 0;
        }
    }
    frame->initRoomPopulations(frame->getCameras());
    return frame;
}

Frame *Network::getKinectFrame()
{
    //TODO stub
}


} // namespace network

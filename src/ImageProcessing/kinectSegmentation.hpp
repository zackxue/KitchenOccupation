#ifndef KINECTSEGMENTATION_HPP
#define KINECTSEGMENTATION_HPP

#include "../Utilities/utilities.hpp"
#include "../Utilities/FrameList.hpp"
#include "../Utilities/Algorithm.hpp"

namespace image_processing
{
/*!
 *  \brief   Process step which creates binary image using OpenCV function KinectSegmentation2.
 */
class KinectSegmentation : public Algorithm
{
public:
    /*!
       \brief   Constructor.
    */
    KinectSegmentation();

    /*!
       \brief   Destructor.
    */
    ~KinectSegmentation();

    /*!
       \brief   Performs the background modulation.
    */
    void process(FrameList &frames) override;

    /*!
       \brief   Initialize the algorithm.
       \details Returns false if initialization fails,
                e.g. if a required variable is not set
    */
    bool initialize(configuration::ConfigurationManager &conf) override;

private:
    float maxIntensity;

};

}

#endif

#ifndef msr_air_copter_sim_ImuBase_hpp
#define msr_air_copter_sim_ImuBase_hpp


#include "sensors/SensorBase.hpp"


namespace msr { namespace airlib {

class ImuBase  : public SensorBase {
public: //types
    struct Output {	//structure is same as ROS IMU message
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Quaternionr orientation;
        Vector3r angular_velocity;
        Vector3r linear_acceleration;
    };


public:
    virtual void reportState(StateReporter& reporter) override
    {
        //call base
        UpdatableObject::reportState(reporter);

        reporter.writeValue("IMU-Ang", output_.angular_velocity);
        reporter.writeValue("IMU-Lin", output_.linear_acceleration);
    }

    const Output& getOutput() const
    {
        return output_;
    }

protected:
    void setOutput(const Output& output)
    {
        output_ = output;
    }


private: 
    Output output_;
};


}} //namespace
#endif 

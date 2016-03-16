#include <rtt/Port.hpp>
#include <std_msgs/String.h>

class Rtt_listener : public RTT::TaskContext{

  protected:
    RTT::InputPort<std_msgs::String> input_port;
    
  private:
    std_msgs::String msg;
};
#endif

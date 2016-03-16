#include <rtt/Port.hpp>
#include <std_msgs/String.h>

class Rtt_talker : public RTT::TaskContext{
  protected:
    RTT::OutputPort<std_msgs::String> output_port;
    int init_count;
      
  private:
    int count;
    std_msgs::String msg;
    std::stringstream sstream;
};
#endif

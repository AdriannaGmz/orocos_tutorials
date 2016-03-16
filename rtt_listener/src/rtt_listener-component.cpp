Rtt_listener::Rtt_listener(std::string const& name) : TaskContext(name){
  ports()->addPort("In", input_port); //addPort or addEventPort
}

void Rtt_listener::updateHook(){
  // DO NOT INITIALIZE MEMORY at RUNTIME std_msgs::String msg;
  std::cout << "Rtt_listener listening !" <<std::endl;
  if (input_port.read(msg) == RTT::NewData) 
  {
    std::cout << "I heard: [" << msg.data << "]" << std::endl;
  }
}

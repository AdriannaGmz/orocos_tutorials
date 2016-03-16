Rtt_talker::Rtt_talker(std::string const& name) : TaskContext(name){
  init_count = 0;
  this->addProperty("init_count", init_count);
  ports()->addPort("Out", output_port);
}

bool Rtt_talker::configureHook(){
  count = init_count;
}

void Rtt_talker::updateHook(){
  // DO NOT INITIALIZE MEMORY at RUNTIME std_msgs::String msg;
  // DO NOT INITIALIZE MEMORY at RUNTIME std::stringstream sstream;
  std::cout << "Rtt_talker talking !" <<std::endl;
  sstream << "hello world " << count;
  msg.data = sstream.str();
  output_port.write(msg);
  sstream.str( std::string() );
  sstream.clear();
  ++count;
}

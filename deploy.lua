require "rttlib"
require "rttros"

tc=rtt.getTC()
d=tc:getPeer("Deployer")

-- ROS integration
d:import("rtt_rosnode")
d:import("rtt_roscomm")
--d:import("rtt_std_msgs")
-- End of user code

d:import("rtt_talker")
d:import("rtt_listener")

-- listener
lstname = "LST"
d:loadComponent(lstname, "Rtt_listener")
d:setActivity(lstname, 0, 0, rtt.globals.ORO_SCHED_RT)
lst = d:getPeer(lstname)
lst:configure()

-- talker 
tlkname = "TLK"
d:loadComponent(tlkname, "Rtt_talker")
d:setActivity(tlkname, 0.1, 10, rtt.globals.ORO_SCHED_RT)
tlk = d:getPeer(tlkname)
--myprop=tlk:getProperty("init_count")
--myprop:set(200)
tlk:configure()

-- connect to ros
--local ros=rtt.provides("ros")
--d:stream("TLK.Out",ros:topic("/chatter"))
--d:stream("LST.In",ros:topic("/chatter"))

-- connection
d:connect("TLK.Out", "LST.In", rtt.Variable("ConnPolicy"))

lst:start()
tlk:start()

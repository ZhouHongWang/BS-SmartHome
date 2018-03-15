package bs.pi.gateway.main;

import bs.pi.gateway.msg.IMsg;

public interface ISender {

	public final static String V_SEND_NAME_HTTP_SNEDER = "HttpSender";
	public final static String V_SEND_NAME_PORT_SNEDER = "PortSender";
	public final static String V_SEND_NAME_ZIGBEE_SNEDER = "ZigbeeSender";
	
	public String getName();
	public IMsg send(IMsg msg);
}
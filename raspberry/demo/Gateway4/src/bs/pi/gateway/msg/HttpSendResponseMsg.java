package bs.pi.gateway.msg;

public class HttpSendResponseMsg implements IMsg {

	public final static String MSG_NAME = "HttpSendResponseMsg";
	public final static int TYPE = 1;
	
	private boolean sendSuccess;
	private int RequestType;
	
	@Override
	public String getName() {
		return MSG_NAME;
	}

	public boolean getSendSuccess() {
		return sendSuccess;
	}

	public void setSendSuccess(boolean sendSuccess) {
		this.sendSuccess = sendSuccess;
	}

	public int getRequestType() {
		return RequestType;
	}

	public void setRequestType(int requestType) {
		RequestType = requestType;
	}
	
}
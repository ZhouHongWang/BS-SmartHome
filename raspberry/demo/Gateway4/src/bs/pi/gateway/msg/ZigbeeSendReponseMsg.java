package bs.pi.gateway.msg;

public class ZigbeeSendReponseMsg implements IMsg {

	public final static String MSG_NAME = "ZigbeeSendResponseMsg";
	
	private boolean sendSuccess;
	
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
}
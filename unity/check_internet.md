# CheckInternet
```
public class Example : MonoBehaviour
{
    string m_ReachabilityText;

    void Update()
    {
//Output the network reachability to the console window
        Debug.Log("Internet : " + m_ReachabilityText);
        // 인터넷 X
        if (Application.internetReachability == NetworkReachability.NotReachable)
        {
            //Change the Text
            m_ReachabilityText = "Not Reachable.";
        }
        // 데이터 연결
		else if (Application.internetReachability == NetworkReachability.ReachableViaCarrierDataNetwork)
        {
            m_ReachabilityText = "Reachable via carrier data network.";
        }
        // 와이파이 연결
        else if (Application.internetReachability == NetworkReachability.ReachableViaLocalAreaNetwork)
        {
            m_ReachabilityText = "Reachable via Local Area Network.";
        }
    }
}
```

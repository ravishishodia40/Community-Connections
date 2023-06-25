// Imports
import android.location.Location
import java.util.*
import java.util.concurrent.Executors
import android.content.Context
import android.location.Geocoder
import android.net.ConnectivityManager
import android.util.Log

// Constants Declaration
const val TAG = "Community Connections"
const val RADIUS_METERS = 10000
const val SERVICE_NUMBER = 1234567

// Interfaces Declaration
interface NetworkListener {
    fun onNetworkStateChange(showMessage: Boolean)
}

// Enums Declaration
enum class EventType {
    LOCAL,
    NATIONAL,
    INTERNATIONAL
}

// Classes Declaration
class Event(val name: String,
            val type: EventType,
            val startDate: Date,
            val endDate: Date,
            val description: String)

class NetworkChecker(private val context: Context,
                     private val networkListener: NetworkListener) {

    private val connectivityManager =
            context.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager

    fun startNetworkMonitoring() {
        Executors
            .newSingleThreadExecutor()
            .submit {
                while (true) {
                    val networkInfo = connectivityManager.activeNetworkInfo

                    if (networkInfo != null && networkInfo.isConnected) {
                        networkListener.onNetworkStateChange(false)
                        break
                    } else {
                        networkListener.onNetworkStateChange(true)
                    }

                    Thread.sleep(1000)
                }
            }
    }

}

class EventsFinder(private val context: Context,
                   private val location: Location,
                   private val radius: Int) {

    private val geocoder = Geocoder(context)

    fun findEvents(): List<Event> {
        val events = mutableListOf<Event>()

        val addresses = geocoder.getFromLocation(
                location.latitude,
                location.longitude,
                1
        )

        if (addresses.isNotEmpty()) {
            val address = addresses[0]
            val locality = address.locality

            // Search for events in the locality within the specified radius
            // Add each found event to the events list
            // ...
        }

        return events
    }

}

class CommunityConnections(context: Context,
                           location: Location) {

    private val radius = RADIUS_METERS
    private val networkChecker = NetworkChecker(context,
            object : NetworkListener {
                override fun onNetworkStateChange(showMessage: Boolean) {
                    if (showMessage) {
                        Log.d(TAG, "Check your connection")
                    } else {
                        start()
                    }
                }
            })
    private val eventsFinder = EventsFinder(context, location, radius)

    fun start() {
        val events = eventsFinder.findEvents()

        Log.d(TAG, "Found ${events.size} events in the vicinity")
        Log.d(TAG, "Call ${SERVICE_NUMBER} for more information")
    }

    fun startNetworkMonitoring() {
        networkChecker.startNetworkMonitoring()
    }

}
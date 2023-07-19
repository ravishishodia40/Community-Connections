/*
 * Community Connections
 *
 * File: MyCommunityConnection.scala
 *
 * Author: Sam Smith
 *
 * Date: May 2020
 */

// Imports
import scala.collection.mutable.Map

// Main class
class MyCommunityConnection {

  // Variables
  private var organizationName: String = ""
  private var zipCode: Int = 0
  private var serviceMap: Map[String,List[String]] = Map()

  // Constructor
  def this(name: String, code: Int) = {
    this()
    organizationName = name
    zipCode = code
    createServiceMap()
  }

  // Create a map linking services to providers
  def createServiceMap(): Unit = {
    serviceMap += ("Food Meals" -> List("Meals on Wheels", "Local Food Bank"))
    serviceMap += ("Transportation" -> List("Volunteer Drivers", "Public Transit"))
    serviceMap += ("Child Care" -> List("In-Home Care", "Day Care Centers"))
    serviceMap += ("Elder Care" -> List("Home Visit Program", "Senior Center"))
    serviceMap += ("Educational" -> List("Tutoring", "Adult Education"))
    serviceMap += ("Health Care" -> List("Free Clinic", "Mobile Medical Unit"))
  }

  // Add Provider
  def addProvider(service: String, provider: String): Unit = {
    if (serviceMap.contains(service)) {
      serviceMap(service) = provider :: serviceMap(service)
    }
    else {
      serviceMap += (service -> List(provider))
    }
  }

  // Get Providers
  def getProvider(service: String): List[String] = {
    serviceMap.getOrElse(service, List())
  }

  // Find Services
  def findServices(zipCode: Int): List[String] = {
    val services: List[String] = serviceMap.keys.toList
    services.filter(s => getProvider(s).exists(p => providerInZip(p, zipCode)))
  }

  // Check if Provider is in Zip
  def providerInZip(provider: String, zipCode: Int): Boolean = {
    // Implement this
    return true
  }

  // Get Name
  def getName(): String = {
    return organizationName
  }

  // Get Zip
  def getZip(): Int = {
    return zipCode
  }
}

// Sub-classes
class FoodMeals extends MyCommunityConnection {
  def this(name: String, code: Int) = {
    super(name, code)
  }
}

class Transportation extends MyCommunityConnection {
  def this(name: String, code: Int) = {
    super(name, code)
  }
}

class ChildCare extends MyCommunityConnection {
  def this(name: String, code: Int) = {
    super(name, code)
  }
}

class ElderCare extends MyCommunityConnection {
  def this(name: String, code: Int) = {
    super(name, code)
  }
}

class Educational extends MyCommunityConnection {
 def this(name: String, code: Int) = {
    super(name, code)
  }
}

class HealthCare extends MyCommunityConnection {
  def this(name: String, code: Int) = {
    super(name, code)
  }
}

// Main Method
object main {
  def main(args: Array[String]): Unit = {
    val myOrgOne = new MyCommunityConnection("MyOrgOne", 11111)
    myOrgOne.addProvider("Food Meals", "My Food Bank")
    println("Food Meals Providers: " + myOrgOne.getProviders("Food Meals"))
    val services = myOrgOne.findServices(11111)
    println("Services in Zip 11111: " + services)
  }
}
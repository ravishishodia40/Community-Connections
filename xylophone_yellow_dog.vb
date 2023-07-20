Public Class CommunityConnections
	Private _firstName As String
	Private _lastName As String
	Private _address As String
	Private _state As String
    Private _zip As String
	
	Public Sub New (ByVal fName As String, ByVal lName As String, ByVal addr As String,
                    ByVal state As String, ByVal zip As String)
		_firstName = fName
		_lastName = lName
		_address = addr
		_state = state
		_zip = zip
	End Sub
    
	Public Sub SetFirstName(ByVal fName As String)
		_firstName = fName
	End Sub
	
	Public Function GetFirstName() As String
		Return _firstName
	End Function
	
	Public Sub SetLastName(ByVal lName As String)
		_lastName = lName
	End Sub
	
	Public Function GetLastName() As String
		Return _lastName
	End Function
    
	Public Sub SetAddress(ByVal addr As String)
		_address = addr
	End Sub
	
	Public Function GetAddress() As String
		Return _address
	End Function
	
	Public Sub SetState(ByVal state As String)
		_state = state
	End Sub
	
	Public Function GetState() As String
		Return _state
	End Function
	
	Public Sub SetZip(ByVal zip As String)
		_zip = zip
	End Sub
	
	Public Function GetZip() As String
		Return _zip
	End Function	
	
	Public Sub JoinCommunity(ByVal newMember As CommunityConnections)
		Dim count As Integer = 0
		For Each member As CommunityConnections In CommunityList
			If (member.GetFirstName.Equals(newMember.GetFirstName) And
				member.GetLastName.Equals(newMember.GetLastName) And
				member.GetAddress.Equals(newMember.GetAddress) And
				member.GetState.Equals(newMember.GetState) And
				member.GetZip.Equals(newMember.GetZip)) Then
				
				count += 1
			End If
		Next
		If count = 0 Then
			CommunityList.Add(newMember)
		End If
	End Sub
    
	Public Sub PrintCommunityMembers()
		For Each member As CommunityConnections In CommunityList
			Console.WriteLine("First Name: {0}", member.GetFirstName)
			Console.WriteLine("Last Name: {0}", member.GetLastName)
			Console.WriteLine("Address: {0}", member.GetAddress)
			Console.WriteLine("State: {0}", member.GetState)
			Console.WriteLine("Zip Code: {0}", member.GetZip)
			Console.WriteLine("--------------------------------")
		Next
	End Sub
    
	Private CommunityList As New List(Of CommunityConnections)
End Class
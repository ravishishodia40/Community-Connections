# FILE: Community_Connections.py

# Imports
import requests
import json
import os
import sys
import time

# Global constants
BASE_URL = 'https://api.communityconnections.org/v1/'

# Initialize and hold keys and access tokens
ACCESS_TOKEN = None
REFRESH_TOKEN = None

# Functions
def set_access_tokens(access_token, refresh_token):
    '''
    Sets access and refresh tokens
    
    Parameters:
        access_token (string): Access token
        refresh_token (string): Refresh token
    '''
    global ACCESS_TOKEN
    global REFRESH_TOKEN
    ACCESS_TOKEN = access_token
    REFRESH_TOKEN = refresh_token

def get_access_token_from_code(client_id, client_secret, code):
    '''
    Retrieves access token and refresh token from oauth code
    
    Parameters:
        client_id (string): Client ID
        client_secret (string): Client Secret
        code (string): OAuth code
    
    Returns:
        access_token (string): Access token
        refresh_token (string): Refresh token
    '''
    # Make request to Community Connections API
    data = {
        'client_id': client_id,
        'client_secret': client_secret,
        'code': code
    }
    headers = {'Content-Type': 'application/x-www-form-urlencoded'}
    r = requests.post(url=BASE_URL + 'token', data=data, headers=headers)
    # Retrieve access and refresh tokens from response
    access_token = r.json()['access_token']
    refresh_token = r.json()['refresh_token']
    # Set access and refresh tokens
    set_access_tokens(access_token, refresh_token)
    return access_token, refresh_token

def get_access_token_from_refresh_token(client_id, client_secret):
    '''
    Retrieves access token from refresh token
    
    Parameters:
        client_id (string): Client ID
        client_secret (string): Client Secret
    
    Returns:
        access_token (string): Access token
    '''
    # Make request to Community Connections API
    data = {
        'client_id': client_id,
        'client_secret': client_secret,
        'refresh_token': REFRESH_TOKEN
    }
    headers = {'Content-Type': 'application/x-www-form-urlencoded'}
    r = requests.post(url=BASE_URL + 'token', data=data, headers=headers)
    # Retrieve access token from response
    access_token = r.json()['access_token']
    # Set access token
    set_access_tokens(access_token, REFRESH_TOKEN)
    return access_token

def get_organizations(page_number, page_size):
    '''
    Retrieves list of organizations
    
    Parameters:
        page_number (int): Page number
        page_size (int): Page size
    
    Returns:
        organizations (list of dicts): List of organizations
    '''
    payload = {'page_number': page_number, 'page_size': page_size}
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'organizations',
                     params=payload,
                     headers=headers)
    organizations = r.json()['organizations']
    return organizations

def get_organization_by_id(organization_id):
    '''
    Retrieves organization by ID
    
    Parameters:
        organization_id (string): Organization ID
    
    Returns:
        organization (dict): Organization
    '''
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'organizations/' + organization_id,
                     headers=headers)
    organization = r.json()['organization']
    return organization

def get_events(page_number, page_size):
    '''
    Retrieves list of events
    
    Parameters:
        page_number (int): Page number
        page_size (int): Page size
    
    Returns:
        events (list of dicts): List of events
    '''
    payload = {'page_number': page_number, 'page_size': page_size}
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'events',
                     params=payload,
                     headers=headers)
    events = r.json()['events']
    return events

def get_event_by_id(event_id):
    '''
    Retrieves event by ID
    
    Parameters:
        event_id (string): Event ID
    
    Returns:
        event (dict): Event
    '''
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'events/' + event_id,
                     headers=headers)
    event = r.json()['event']
    return event

def get_locations(page_number, page_size):
    '''
    Retrieves list of locations
    
    Parameters:
        page_number (int): Page number
        page_size (int): Page size
    
    Returns:
        locations (list of dicts): List of locations
    '''
    payload = {'page_number': page_number, 'page_size': page_size}
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'locations',
                     params=payload,
                     headers=headers)
    locations = r.json()['locations']
    return locations

def get_location_by_id(location_id):
    '''
    Retrieves location by ID
    
    Parameters:
        location_id (string): Location ID
    
    Returns:
        location (dict): Location
    '''
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.get(url=BASE_URL + 'locations/' + location_id,
                     headers=headers)
    location = r.json()['location']
    return location

def create_event(title, start_date, end_date, description, organization_id):
    '''
    Creates event
    
    Parameters:
        title (string): Title
        start_date (string): Start date
        end_date (string): End date
        description (string): Description
        organization_id (string): Organization ID
    
    Returns:
        event (dict): Event
    '''
    data = {
        'title': title,
        'start_date': start_date,
        'end_date': end_date,
        'description': description,
        'organization_id': organization_id
    }
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.post(url=BASE_URL + 'events',
                      data=json.dumps(data),
                      headers=headers)
    event = r.json()['event']
    return event

def update_event(event_id, title, start_date, end_date, description):
    '''
    Updates event
    
    Parameters:
        event_id (string): Event ID
        title (string): Title
        start_date (string): Start date
        end_date (string): End date
        description (string): Description
    
    Returns:
        event (dict): Event
    '''
    data = {
        'title': title,
        'start_date': start_date,
        'end_date': end_date,
        'description': description
    }
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.put(url=BASE_URL + 'events/' + event_id,
                     data=json.dumps(data),
                     headers=headers)
    event = r.json()['event']
    return event

def delete_event(event_id):
    '''
    Deletes event
    
    Parameters:
        event_id (string): Event ID
    
    Returns:
        None
    '''
    headers = {'Authorization': 'Bearer {}'.format(ACCESS_TOKEN)}
    r = requests.delete(url=BASE_URL + 'events/' + event_id,
                        headers=headers)

# Main
if __name__ == '__main__':
    # Set client_id and client_secret
    client_id = os.environ.get('COMMUNITYCONNECTIONS_CLIENT_ID', None)
    client_secret = os.environ.get('COMMUNITYCONNECTIONS_CLIENT_SECRET', None)
    if client_id == None or client_secret == None:
        print('Set client_id and client_secret as environment variables')
        sys.exit()

    # Get oauth code from user
    code = input('Enter OAuth code: ')

    # Get access and refresh tokens using oauth code
    access_token, refresh_token = get_access_token_from_code(client_id, client_secret, code)
    print('Access token: {}\nRefresh token: {}'.format(access_token, refresh_token))
    print('\n')

    # Get list of organizations
    organizations = get_organizations(1, 10)
    print('Organizations:')
    for organization in organizations:
        print(organization['id'] + ': ' + organization['name'])
    print('\n')

    # Get organization by ID
    organization_id = input('Enter organization ID: ')
    organization = get_organization_by_id(organization_id)
    print('Organization: ' + organization['name'] + '\n')

    # Get list of events
    events = get_events(1, 10)
    print('Events:')
    for event in events:
        print(event['title'] + ' (ID: ' + event['id'] + ')')
    print('\n')

    # Get event by ID
    event_id = input('Enter event ID: ')
    event = get_event_by_id(event_id)
    print('Event: ' + event['title'] + '\n')

    # Get list of locations
    locations = get_locations(1, 100)
    print('Locations:')
    for location in locations:
        print(location['name'] + ' (ID: ' + location['id'] + ')')
    print('\n')

    # Get location by ID
    location_id = input('Enter location ID: ')
    location = get_location_by_id(location_id)
    print('Location: ' + location['name'] + '\n')

    # Create event
    title = input('Enter event title: ')
    start_date = input('Enter start date: ')
    end_date = input('Enter end date: ')
    description = input('Enter description: ')
    event = create_event(title, start_date, end_date, description, organization_id)
    print('Event created: ' + event['title'] + '\n')

    # Update event
    new_title = input('Enter new title: ')
    new_start_date = input('Enter new start date: ')
    new_end_date = input('Enter new end date: ')
    new_description = input('Enter new description: ')
    event = update_event(event_id, new_title, new_start_date, new_end_date, new_description)
    print('Event updated: ' + event['title'] + '\n')

    # Delete event
    delete_event(event_id)
    time.sleep(2)
    print('Event deleted')
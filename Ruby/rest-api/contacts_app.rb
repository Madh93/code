# Contact List App based on REST API
#
# Usage:
#
# => curl -X GET "localhost:4567/"
#    'Contact List App based on REST API'
#
# => curl -X GET "localhost:4567/contacts"
#    {
#      { "id": "1", "name": "Alice", "number": "611222333" },
#      { "id": "2", "name": "Bob", "number": "611444555" }
#    }
#
# => curl -X GET "localhost:4567/contacts/2"
#    { "id": "2", "name": "Bob", "number": "611444555" }
#
# => curl -X POST "localhost:4567/contacts/3?name=Carol&number=611666777"
# => curl -X GET "localhost:4567/contacts"
#    {
#      { "id": "1", "name": "Alice", "number": "611222333" },
#      { "id": "2", "name": "Bob", "number": "611444555" },
#      { "id": "3", "name": "Carol", "number": "611666777" }
#    }
#
# => curl -X PUT "localhost:4567/contacts/2?name=Dylan"
# => curl -X GET "localhost:4567/contacts/2"
#    { "id": "2", "name": "Dylan", "number": "611444555" }
#
# => curl -X DELETE "localhost:4567/contacts/1"
# => curl -X GET "localhost:4567/contacts"
#    {
#      { "id": "2", "name": "Bob", "number": "611444555" },
#      { "id": "3", "name": "Carol", "number": "611666777" }
#    }
#

require 'sinatra'
require 'json'
require './contact_list'

contacts = ContactList.new

# Index
get '/' do
  'Contact List App based on REST API'
end

# List all
get '/contacts' do
  contacts.all.to_json
end

# View one
get '/contacts/:id' do
  contact = contacts.find(params[:id])
  return status 404 if contact.nil?
  contact.to_json
end

# Create
post '/contacts/:id' do
  contact = contacts.find(params[:id])
  return status 404 unless contact.nil?
  contacts.add(
    id: params[:id],
    name: params[:name],
    number: params[:number]
  )
  status 201
end

# Update
put '/contacts/:id' do
  contact = contacts.find(params[:id])
  return status 404 if contact.nil?
  contacts.update(
    id: params[:id],
    name: params[:name],
    number: params[:number]
  )
  status 202
end

# Delete
delete '/contacts/:id' do
  contact = contacts.find(params[:id])
  return status 404 if contact.nil?
  contacts.remove(params[:id])
  status 202
end

## Installation Instructions

### Installing CouchDB

#### Enabling the Apache CouchDB package repository

	echo "deb https://apache.bintray.com/couchdb-deb bionic main" \
	| sudo tee -a /etc/apt/sources.list


---


#### Installing the Apache CouchDB packages

	curl -L https://couchdb.apache.org/repo/bintray-pubkey.asc \
	| sudo apt-key add -


---

#### Update repo and install couchdb:

	sudo apt-get update && sudo apt-get install couchdb


---

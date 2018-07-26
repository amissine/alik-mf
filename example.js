'use strict'

const debug = require('debug')('example')
const Grenache = require('grenache-nodejs-http')
const Link = require('grenache-nodejs-link')

const Peer = Grenache.PeerRPCClient

const link = new Link({
  grape: 'http://127.0.0.1:30001'
})

link.start()

const peer = new Peer(link, {})
peer.done = process.exit
peer.init()

const query = {
  action: 'getHelloWorld',
  args: [ { name: 'Paolo' } ]
}

peer.request('alik:mf', query, { timeout: 10000 }, (err, data) => {
  if (err) {
    console.error(err)
    process.exit(1)
  }

  console.log('query response:')
  console.log(data)
  console.log('---')
  // debug(peer.tpool.getActive('127.0.0.1:1331')[0])
  debug('peer.foo=%s', peer.foo)
  peer.done()
})

exports.peer = peer

/* eslint-env mocha */

'use strict'

const { spawn } = require('child_process')
const dpBase = 20000
const aphBase = 30000

var nodeCount = 0

describe('Test on macOS', () => {
  before('Start 2 DHT nodes and 1 worker', done => {
    spawn('ttab', nodeArgs())
    spawn('ttab', nodeArgs())
    spawn('ttab', workerArgs())
    done()
  })
  after('Stop all nodes', done => {
    done()
  })
  it('runs example', done => {
    let peer = require('../../example')
    peer.done = done
  }).timeout(9000)
})
function nodeArgs () {
  let bn = `'127.0.0.1:${dpBase + nodeCount++}'`
  let args = ['-w', '-t', `node ${nodeCount}`]
  let dp = dpBase + nodeCount
  let aph = aphBase + nodeCount
  args.push(`DEBUG=* grape --dp ${dp} --aph ${aph} --bn ${bn}`)
  return args
}
function workerArgs () {
  let args = ['-w', '-t', 'worker', '-d', '../../']
  args.push('node worker.js --env=development --wtype=wrk-alik-mf-api --apiPort 1331')
  return args
}

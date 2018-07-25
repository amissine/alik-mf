/* eslint-env mocha */

'use strict'

const { spawn } = require('child_process')
const dpBase = 20000
const aphBase = 30000

var nodeCount = 0

describe('Test on macOS', () => {
  before('Start 2 DHT nodes and 1 worker', done => {
    spawn('ttab', nodeArgs())
    setTimeout(spawn, 2000, 'ttab', nodeArgs())
    setTimeout(spawn, 4000, 'ttab', workerArgs())
    done()
  })
  after('Stop all nodes', done => {
    done()
  })
  it('runs the example', done => {
    setTimeout(() => {
      require('../../example')
      setTimeout(() => {
        done()
      }, 8000)
    }, 8000)
  }).timeout(20000)
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
  args.push('DEBUG=* node worker.js --env=development --wtype=wrk-alik-mf-api --apiPort 1331')
  return args
}

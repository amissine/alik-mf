#!/usr/bin/env node
/*
 * Usage example:
 *
 *   DEBUG=* ./demo/01\ Fast\ File\ IO.js ~/feeds/hmf.json /tmp/hmf.json
 */
var program = require('commander')
var source, target

program
  .arguments('<source_file> <target_file>')
  .action((src, dst) => {
    source = src
    target = dst
  })
  .parse(process.argv)
if (!source || !target) return program.help()

const dbgcp = require('debug')('cp:cp')
dbgcp('copy %s to %s with cp command', source, target)
const { spawn } = require('child_process')
const cp = spawn('cp', [source, target])
cp.on('close', code => {
  dbgcp('exited with code %d', code)
  copy2()
})

function copy2 () {
  const dbgfs = require('debug')('cp:fs')
  const fs = require('fs')
  dbgfs('copy %s to %s with NodeJS fs', source, target)
  fs.copyFile(source, target, err => {
    if (err) throw err

    dbgfs('done')
    copy3()
  })
}

function copy3 () {
  const dbgus = require('debug')('cp:µs')
  dbgus('copy %s to %s with µSockets', source, target)
  setTimeout(dbgus, 1, 'done')
}

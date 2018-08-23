#!/usr/bin/env node

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

console.log('- copy', source, 'to', target, 'with cp command')
console.log('- copy', source, 'to', target, 'with NodeJS fs')
console.log('- copy', source, 'to', target, 'with µSockets')

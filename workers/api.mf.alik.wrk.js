'use strict'

const debug = require('debug')('alik:mf')
const { WrkApi } = require('bfx-wrk-api')

class WrkalikMfApi extends WrkApi {
  constructor (conf, ctx) {
    super(conf, ctx)

    this.loadConf('mf.alik', 'alik')

    this.init()
    this.start()
  }

  getPluginCtx (type) {
    const ctx = super.getPluginCtx(type)

    switch (type) {
      case 'api_bfx':
        // ctx.foo = 'bar'
        break
    }

    return ctx
  }

  init () {
    super.init()
  }
}

module.exports = WrkalikMfApi

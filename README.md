# alik-mf

## Setup

Run two Grapes:

```
grape --dp 20001 --aph 30001 --bn '127.0.0.1:20002'
grape --dp 20002 --aph 40001 --bn '127.0.0.1:20001'
```

```
# Add base as upstream:
git remote add upstream https://github.com/bitfinexcom/bfx-util-js

# Configure service:
cp config/common.json.example config/common.json
cp config/facs/grc.config.json.example config/facs/grc.config.json
cp config/mf.alik.json.example config/mf.alik.json
```


### Boot worker

```
node worker.js --env=development --wtype=wrk-alik-mf-api --apiPort 1331
```

## Grenache API

### action: 'getHelloWorld'

  - `args`: &lt;Array&gt;
    - `0`: &lt;Object&gt;
      - `name`: &lt;String&gt; Name to greet

**Response:**

  - &lt;String&gt; The Greeting

**Example Payload:**

```js
args: [ { name: 'Paolo' } ]
```

**Example Response:**

```js
'Hello Paolo'
```

Example: [example.js](example.js)

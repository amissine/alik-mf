# alik-mf

The Market Feed project is a component of the ALI Kernel suite of projects. The market feed itself is one or more streams of trades and orders from one or more token exchanges. The goal of the project is to pass this feed to the customer in a _secure_, _reliable_ and _scalable_ manner.

 - _Security_ guarantees the customer is the only feed recipient and no man-in-the-middle attack can compromize the feed.
 - _Reliability_ guarantees the feed is available to the customer for as long as it is available from the token exchange.
 - _Scalability_ guarantees the latency of the feed remains minuscule as the number of participating token exchanges grows with time.

The feed can be passed to the customer by the Market Feed Local Agent (MFLA) component in a number of ways. For example, the MFLA can produce one or more files `./feed1, ./feed2, ..., ./feedZ`to be read by the customer with `tail -f ./feedN`. Or you can pipe MFLA __sysout__ to the customer's __sysin__ with `./mfla | ./customer`. Or any other custom solution can be used.

When the MFLA component resides on the customer's device, it receives the market feed from the ALIK cloud over SSH. When the customer component is part of the ALIK cloud, no SSH is required. The ALIK cloud is based on the [Grenache Grape](https://github.com/amissine/grenache-grape.git) solution from [Bitfinex](https://github.com/bitfinexcom/grenache.git). The examples in the `./demo` directory cover some use cases.
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

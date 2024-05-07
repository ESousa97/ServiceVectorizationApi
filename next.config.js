// next.config.js
module.exports = {
  async rewrites() {
    return [
      {
        source: '/vectorize',
        destination: process.env.NODE_ENV === 'production' ? 'https://service-vectorization-api.vercel.app/vectorize' : 'http://localhost:5003/vectorize',
      },
      {
        source: '/api/:path*',
        destination: process.env.NODE_ENV === 'production' ? 'https://service-vectorization-api.vercel.app/api/:path*' : 'http://localhost:5003/:path*',
      },
    ]
  },
};

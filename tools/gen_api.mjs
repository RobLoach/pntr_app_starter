// this will generate the API definition from pntr headers & requires you to build once (to download upstream headers)

import { readFile, writeFile } from 'fs/promises'

const regex = /(PNTR_APP_API|PNTR_API) (.+) (.+)\((.+)\);/gm
const str = (await readFile('build/_deps/pntr-src/pntr.h', 'utf8')) + (await readFile('build/_deps/pntr_app-src/include/pntr_app.h', 'utf8'))

const methods = []
let m
while ((m = regex.exec(str)) !== null) {
  methods.push({
    name: m[3].trim(),
    returns: m[2].trim(),
    args: m[4].split(',').map(s => {
      const i = s.trim().split(' ')
      return [i.at(-1), i.slice(0, -1).join(' ')]
    })
  })
}

await writeFile('api.json', JSON.stringify(methods, null, 2))

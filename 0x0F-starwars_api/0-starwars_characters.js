#!/usr/bin/node

const request = require('request');

if (process.argv.length === 3) {
    starwars(process.argv[2]);
}

async function starwars (id) {
    const url = 'https://swapi-api.hbtn.io/api/films/' + id;

    request(url, async function(error, response, body) {
        if (error) {
            console.log(error);
        } else {
            const characters = (JSON.parse(body).characters);
            for (let i = 0; i < characters.length; i++)
            {
                const new_promise = new Promise(function(resolver, rechazar) {
                    request(characters[i], function(error, response, body) {
                        if (error) {
                            rechazar(error);
                        } else {
                            resolver(JSON.parse(body).name);
                        }
                    });
                });
                //console.log("Print");
                console.log(await new_promise);
            }
            //console.log(typeof(characters));
            //console.log(characters);
            //console.log(characters.length)
        }
    });
}

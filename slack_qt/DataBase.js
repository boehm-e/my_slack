.pragma library
.import QtQuick.LocalStorage 2.0 as Sql

var db = Sql.LocalStorage.openDatabaseSync("Local Storage Example", "1.0", "Sample database", 100000);

function init() {
    db.transaction(function(tx) {
        tx.executeSql('CREATE TABLE IF NOT EXISTS songs(path VARCHAR(500) PRIMARY KEY, cover VARCHAR(50), artist VARCHAR(50), name VARCHAR(50), lyrics VARCHAR(10000));')
    })
}

function getRecords() {
    var songs = []

    db.transaction(function(tx) {
        var rs = tx.executeSql('SELECT * FROM songs;');
        for (var i = 0; i < rs.rows.length; i++) {
            songs.push(rs.rows.item(i))
        }
    });

    return songs;
}

function addSong(obj) {
    db.transaction(function(tx) {
        tx.executeSql('INSERT OR IGNORE INTO songs(path, cover, artist, name) VALUES(?, ?, ?, ?);', [obj.path, obj.cover, obj.artist, obj.name]);
    });
}

function addLyrics(songPath, lyrics) {
    db.transaction(function(tx) {
        tx.executeSql('UPDATE songs SET lyrics=? WHERE path=?;', [ lyrics, songPath]);
    });
}

function dropDb() {
    db.transaction(function(tx) {
      tx.executeSql('DROP TABLE IF EXISTS songs');
    })
}

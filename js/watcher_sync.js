var baseDir = './test',
    path = require('path'),
    fs = require('fs');

// watch the directory for new files
fs.watch(baseDir,  function(event, file) {
  var ext = path.extname(file),
  basename = path.basename(file).substring(0, path.basename(file).length - ext.length);
  // check it wasnt a delete action
  // check we have the right file type
  var filePath = path.join(baseDir, file);
  if(fs.existsSync(filePath) && ext === '.ogg'){
    // get the created date
    var stats = fs.statSync(filePath);
    var name = getName(stats);
    // if the directory doesnt exist
    var baseDirPath = path.join(baseDir, basename);
    if(!fs.existsSync(baseDirPath)){
      // make the directory
      fs.mkdirSync(baseDirPath, 0777);
    }
    moveFile(file, basename, name, ext);
  }
});


function getName (stats) {
  var year = stats.ctime.getFullYear();
  var month = stats.ctime.getMonth()+1;
  var day = stats.ctime.getDate();
  var hour = stats.ctime.getHours();
  // need minutes!
  var minutes = stats.ctime.getMinutes();
  var sec = stats.ctime.getSeconds();
  if(month < 10){
    month = '0' + month;
  }
  if(day < 10){
    day = '0' + day;
  }
  if(hour < 10){
    hour = '0' + hour;
  }
  if(sec < 10){
    sec = '0' + sec;
  }

  // missing the minute, previously
  return year + '' + month + '' + day + '' + hour + '' + minutes + '' + sec;
}

function moveFile(file, basename, name, ext){
  // move the file to the new directory
  var src = path.join(baseDir, file),
      dest = path.join(baseDir, basename, name+ext);

  console.log("Moving ", src, "->", dest);

  fs.renameSync(src, dest);
}

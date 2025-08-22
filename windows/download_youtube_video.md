#nDownload youtube Video

### 1. Install yt-dlp
```
pip install yt-dlp
```

### 2. Download video as MP4
```
yt-dlp -f mp4 "https://www.youtube.com/watch?v=VIDEO_ID"
```

---
### 1. Download using curl
```
curl -L -o video.mp4 "$(yt-dlp -g https://www.youtube.com/watch?v=VIDEO_ID)"
```

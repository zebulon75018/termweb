<!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Image Compare Viewer</title>
  <link rel='stylesheet' href='https://unpkg.com/image-compare-viewer/dist/image-compare-viewer.min.css'>

</head>
<body>
<!-- partial:index.partial.html -->
<body class="bg-gray-100 p-8 md:p-10">
      <div class="image-compare shadow-lg rounded mb-12">
      <img src="{{img1}}" alt="">
       <img src="{{img2}}" alt="">
      </div>
</body>
<!-- partial -->
  <script src='https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.18.1/highlight.min.js'></script>
<script src='https://unpkg.com/image-compare-viewer'></script>
<script  >


// image-compare-viewer is included in the JS options panel. Use the CDN or npm for your project

hljs.initHighlightingOnLoad();

let imageCompareViewers = document.querySelectorAll(".image-compare");

let configs = [
{
  controlColor: "#4a5568",
  controlShadow: false,
  startingPoint: 75,
  addCircle: true },

{ addCircle: true, verticalMode: true },
{},
{
  controlColor: "#667eea",
  controlShadow: false,
  addCircle: true,
  addCircleBlur: true // default
},
{
  smoothing: false,
  controlShadow: false },

{
  smoothingAmount: 300,
  controlShadow: false },

{
  hoverStart: true,
  controlShadow: false,
  addCircle: true },

{
  verticalMode: true,
  controlShadow: false },

{
  startingPoint: 75,
  controlShadow: false },

{
  fluidMode: true,
  controlShadow: false }];



imageCompareViewers.forEach((element, i) => {
  new ImageCompare(element, configs[i]).mount();
});

// page

const anchors = document.querySelectorAll(".anchor");

anchors.forEach((anchor, i) => {
  anchor.addEventListener("click", function (e) {
    let marker = e.target.dataset.destination;
    let dest = i === 0 ? document.body : document.getElementById(marker);
    dest.scrollIntoView({
      behavior: "smooth",
      block: "start",
      inline: "nearest" });


    toggleActiveClass();
    anchor.classList.add("text-indigo-500");
  });
});

function toggleActiveClass() {
  anchors.forEach(anchor => {
    anchor.classList.remove("text-indigo-500");
    anchor.classList.add("text-gray-500");
  });
}
</script>

</body>
</html>

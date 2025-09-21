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
  <div class="container m-auto flex items-center mb-12 lg:mt-16"><svg height="24" width="35" fill="#5a67d8" class="h-6 mr-2" xmlns="http://www.w3.org/2000/svg" data-name="Layer 1" viewBox="0 0 302.2 205.3">
      <path d="M284.2 0H18A18 18 0 000 18v169.3a18 18 0 0018 18h266.2a18 18 0 0018-18V18a18 18 0 00-18-18zm-139 193.3H18a6 6 0 01-6-6V18a6 6 0 016-6h127.1zm59.6-87.8l-7.7 6.9-10.5 9.3-7.8 6.9c-2.8 2.5-5.2 1.5-5.2-2.4V75.4c0-3.8 2.4-4.9 5.3-2.3l7.7 6.9 10.5 9.3 7.7 6.9a6 6 0 010 9.3z" />
      <path d="M87.4 105.5l7.7 6.9 10.5 9.3 7.7 6.9c3 2.5 5.3 1.5 5.3-2.4V75.4c0-3.8-2.4-4.9-5.3-2.3l-7.7 6.9L95 89.3l-7.7 6.9a6 6 0 000 9.3z" /></svg>
  </div>
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
  startingPoint: 75 },

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

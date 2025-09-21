<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <title>Crop Image depuis une URL</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 20px;
    }
    #canvas, #result {
      border: 1px solid #ccc;
      margin-top: 10px;
      max-width: 100%;
    }
    .controls {
      margin-top: 10px;
    }
  </style>
</head>
<body>

<h2>🖼️ Crop d’image avec forme sélectionnable (image distante)</h2>

<!-- Choix de forme -->
<div class="controls">
  <label><input type="radio" name="cropShape" value="rect" checked> Rectangulaire</label>
  <label><input type="radio" name="cropShape" value="circle"> Circulaire</label>
  <br><br>
  <button id="cropBtn">✂️ Crop</button>
</div>

<!-- Zone de sélection et affichage -->
<canvas id="canvas" width="500" height="400"></canvas>
<h3>Image Croppée :</h3>
<canvas id="result" width="300" height="300"></canvas>

<script src="https://unpkg.com/cropimage/dist/cropimage.min.js"></script>
<script>
  const IMAGE_URL = "https://upload.wikimedia.org/wikipedia/commons/thumb/4/47/PNG_transparency_demonstration_1.png/640px-PNG_transparency_demonstration_1.png";
  const canvas = document.getElementById("canvas");
  const resultCanvas = document.getElementById("result");
  const ctx = canvas.getContext("2d");
  const rctx = resultCanvas.getContext("2d");
  let cropInstance = null;

  const img = new Image();
  img.crossOrigin = "anonymous"; // important pour autoriser drawImage de domaine externe
  img.onload = () => {
    canvas.width = img.width;
    canvas.height = img.height;
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.drawImage(img, 0, 0);
    cropInstance = new CropImage(canvas);
  };
  img.src = IMAGE_URL;

  document.getElementById("cropBtn").addEventListener("click", function () {
    if (!cropInstance) return;

    const shape = document.querySelector('input[name="cropShape"]:checked').value;
    const cropData = cropInstance.getCrop();
    const { x, y, width, height } = cropData;

    resultCanvas.width = width;
    resultCanvas.height = height;
    rctx.clearRect(0, 0, width, height);

    if (shape === "circle") {
      rctx.save();
      rctx.beginPath();
      rctx.arc(width / 2, height / 2, Math.min(width, height) / 2, 0, 2 * Math.PI);
      rctx.clip();
    }

    rctx.drawImage(canvas, x, y, width, height, 0, 0, width, height);

    if (shape === "circle") {
      rctx.restore();
    }
  });
</script>

</body>
</html>


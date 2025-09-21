!DOCTYPE html>
<html lang="en" >
<head>
  <meta charset="UTF-8">
  <title>Monaco diff</title>
  <link rel="stylesheet" href="https://public.codepenassets.com/css/normalize-5.0.0.min.css">

<style>

body, html {
	padding: 0;
	margin: 0;
	height: calc(100vh - 2em);
}
#container {
	height: 100%;
	width: 100%;
	box-sizing: border-box;
}

.actions {
	height: 2em;
	display: flex;
	align-items: center;
	border-top: 1px solid #aaa;
	padding: 0.2em;
	box-sizing: border-box;
}

label {
	padding-right: 0.3em;
}
</style>
</head>
<body>
<!-- partial:index.partial.html -->
<section class="actions">
	<label>Inline</label>
	<input type="checkbox" class="inline-it">
</section>
<section id="container"></section>
<!-- partial -->
  <script src='https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.10.1/min/vs/loader.js'></script>

<script>


const text1 = `{{text1}}`
 const text2 = `{{text2}}`

require.config({ paths: { 'vs': 'https://cdnjs.cloudflare.com/ajax/libs/monaco-editor/0.10.1/min/vs' }});
require(['vs/editor/editor.main'], () => {
	const editor = monaco.editor.createDiffEditor(document.getElementById('container'));
	editor.setModel({
		original: monaco.editor.createModel(text1, 'javascript'),
		modified: monaco.editor.createModel(text2, 'javascript'),
	});
	
	document.querySelector('.inline-it').addEventListener('change', (e) => {
		editor.updateOptions({ renderSideBySide: !e.target.checked });
	});
});
</script>

</body>
</html>

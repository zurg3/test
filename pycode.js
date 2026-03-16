const container = document.getElementById('container');
const input = document.getElementById('input');
const output = document.getElementById('output');
const textarea = document.getElementById('textarea');
const resizer = document.getElementById('resizer');

let pyodide;

const editor = monaco.editor.create(input, {
  value: '',
  placeholder: '',
  language: 'python',
  theme: 'vs-dark',
  contextmenu: true,
  automaticLayout: true,
  accessibilitySupport: 'off',
  autoIndent: 'full',
  autoIndentOnPaste: true,
  'bracketPairColorization.enabled': false,
  colorDecorators: false,
  colorDecoratorsActivatedOn: 'click',
  folding: true,
  fontFamily: 'Menlo, Consolas, "DejaVu Sans Mono", monospace',
  fontSize: 13,
  guides: {
    indentation: true
  },
  insertSpaces: true,
  lineHeight: 1.45,
  lineNumbers: 'on',
  links: true,
  matchBrackets: 'near',
  minimap: {
    enabled: false
  },
  mouseWheelZoom: true,
  multiCursorModifier: 'ctrlCmd',
  occurrencesHighlight: 'off',
  renderLineHighlight: 'line',
  renderWhitespace: 'none',
  scrollBeyondLastLine: false,
  selectionHighlight: false,
  showDeprecated: false,
  stickyScroll: {
    enabled: false
  },
  tabSize: 4
});

async function init_pyodide() {
  pyodide = await loadPyodide();

  pyodide.setStdout({
    batched: (s) => {
      textarea.value += `${s}\n`;
    }
  });
}

init_pyodide();

async function run_code() {
  if (!pyodide) {
    textarea.value = 'Pyodide is loading...';
    return;
  }

  try {
    clear_output();

    let result = await pyodide.runPythonAsync(editor.getValue());

    if (result !== undefined) {
      textarea.value += `>>> ${result}\n`;
    }
  }
  catch (error) {
    textarea.value += `Error: ${error.message}\n`;
  }
}

function clear_output() {
  textarea.value = '';
}

resizer.addEventListener('mousedown', (e) => {
  e.preventDefault();

  document.addEventListener('mousemove', resize);
  document.addEventListener('mouseup', stop_resize);
});

function resize(e) {
  const container_rect = container.getBoundingClientRect();
  const min_height = 50;
  const new_height = e.clientY - container_rect.top;

  if (new_height > min_height && new_height < (container_rect.height - min_height)) {
    input.style.height = `${new_height}px`;
    input.style.flex = `0 0 ${new_height}px`;
  }
}

function stop_resize() {
  document.removeEventListener('mousemove', resize);
  document.removeEventListener('mouseup', stop_resize);
}

const inputs = document.querySelectorAll('input[type="text"], input[type="url"]');

inputs.forEach(input => {
  input.onblur = () => {
    input.value = input.value.trim();
  };
});

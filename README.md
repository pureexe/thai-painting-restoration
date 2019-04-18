# thai-painting-restoration
Thai painting restoration implement in c++ with opencv. This repository is a part of research project in undergraduate degree Silpakorn University.

This repository only support for run on linux (especially [Google Colab](https://colab.research.google.com))

## Usage

```shell
DAMAGED_IMAGE="input.png" INPAINT_DOMAIN="domain.png" ./thai-painting-restoration
```

There also have option avaliable for optimization the result

- DAMAGED_IMAGE: path of image to restoration (required)
- INPAINT_DOMAIN: path of inpaint domain which is binary image on grayscale color space (required)
- OUTPUT_IMAGE: path of image after restoration (default: output.png)
- LAMBDA: lambda parameter in Chan-Shen inpainting model (default: 250)
- THETA: theta parameter in split-breman numerical method (defualt: 5) 
- EPSILON: epsilon aka. tolerant which use to determine neighborhood (defualt: 1e-4) 
- DEPTH: image pyramid depth (default: 4)
- COARSE_STEP: maximum iteration on coarse level resolution of image pyramid (default: 10)
- MIDDLE_STEP: maximum iteration on middle level resolution of image pyramid (default: 3)
- FINEST_STEP: maximum iteration on finest level resolution of image pyramid (default: 10)


## Demonstrate

- Algorithm explain with demonstration (Thai language) [bit.ly/demothai](https://bit.ly/demothai)
- colab example [![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/pureexe/thai-painting-restoration/colab/inpaint.ipynb)

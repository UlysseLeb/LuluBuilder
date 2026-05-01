# Dépendances tierces

Ce dossier accueille les bibliothèques externes qui ne sont pas gérées par CMake FetchContent.

## ONNX Runtime

1. Télécharge la version macOS depuis https://github.com/microsoft/onnxruntime/releases
2. Décompresse dans `third_party/onnxruntime/`
3. Dans `CMakeLists.txt`, décommente la section ONNX Runtime

## Essentia

Build depuis les sources (recommandé) :

```bash
git clone https://github.com/MTG/essentia.git third_party/essentia
cd third_party/essentia
python waf configure --mode=release --no-examples --no-python
python waf
```

Dans `CMakeLists.txt`, décommente la section Essentia une fois buildée.

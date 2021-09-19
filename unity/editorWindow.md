## 1. Make Init()
```c#
using UnityEditor;
public class TestEditor : EditorWindow {
	[MenuItem("Custom/MyCustomEditorWindow"]
	static void Init() {
		TestEditor window = (TestEditor)EditorWindow.GetWindow(typeof(TestEditor));
	}
```

## 2. Draw GUI
```c#
private void OnGUI() {
	EditorGUILayout.BeginHorizontal();
	if (GUILayout.Button("1")) {
		...
	}
	if (GUILayout.Button("2")) {
		...
	}
	if (GUILayout.Button("3")) {
		...
	}
}
```

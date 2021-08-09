ref: [Unity Documentation](https://docs.unity3d.com/Manual/CustomPackages.html)

## 순서
1. Create Package Manifest
	- name, version, displayName, description 등이 필수
	- ref 참고
2. Package layout에 따른 파일 구조 생성
	- 좀 복잡함
	- 기본적으로 Runtime 폴더 안에 assembly definition과 그 코드, Tests/Runtime 안에 같은 내용의 assembly definition과 그 코드가 있으면 패키지 역할은 할 수 있다.

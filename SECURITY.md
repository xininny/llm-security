name: 'CodeQL Analysis'

on:
push:
branches: ['main']
pull_request:
branches: ['main']
schedule: - cron: '0 12 \* \* 1' # 매주 월요일 정기 분석

jobs:
analyze:
name: Analyze
runs-on: ubuntu-latest
permissions:
security-events: write
actions: read
contents: read

        steps:
            - name: Checkout repository
              uses: actions/checkout@v4

            - name: Initialize CodeQL
              uses: github/codeql-action/init@v3
              with:
                  languages: 'cpp'

            - name: Build C Project (Manual Build)
              run: |
                  gcc -o gpt gpt.c  # 🔹 C 코드 수동 빌드
                  ls -l              # 🔹 빌드된 파일 확인

            - name: Perform CodeQL Analysis
              uses: github/codeql-action/analyze@v3

# import httpx

# API_KEY = "sk-junhao-qGLrSfcfu_ObH_VW3DSgos_NcLu9g-sfjjrZzvnhDGQ"
# BASE_URL = "https://junhao-api.sage.org.ai/v1"

# headers = {
#     "Authorization": f"Bearer {API_KEY}",
#     "Content-Type": "application/json",
#     "User-Agent": "python-httpx/0.28.1",
# }

# for model in ["qwen32b", "qwen25-7b"]:
#     payload = {
#         "model": model,
#         "stream": False,
#         "messages": [
#             {"role": "user", "content": "请只回复 OK"}
#         ],
#         "temperature": 0,
#         "max_tokens": 16,
#     }

#     response = httpx.post(
#         f"{BASE_URL}/chat/completions",
#         headers=headers,
#         json=payload,
#         timeout=120.0,
#     )

#     print("\nmodel:", model)
#     print("status:", response.status_code)
#     print("cf-ray:", response.headers.get("cf-ray"))
#     print(response.text[:1000])

#     response.raise_for_status()
#     data = response.json()
#     print("answer:", data["choices"][0]["message"]["content"])
import httpx
from openai import OpenAI

API_KEY = "sk-junhao-qGLrSfcfu_ObH_VW3DSgos_NcLu9g-sfjjrZzvnhDGQ"
BASE_URL = "https://junhao-api.sage.org.ai/v1"

http_client = httpx.Client(
    headers={"User-Agent": "python-httpx/0.28.1"},
    timeout=120.0,
)

client = OpenAI(
    base_url=BASE_URL,
    api_key=API_KEY,
    http_client=http_client,
)

models = client.models.list()
print("Models:")
for model in models.data:
    print("-", model.id)

for model in ["qwen32b", "qwen25-7b"]:
    response = client.chat.completions.create(
        model=model,
        messages=[
            {"role": "user", "content": "请只回复 OK"}
        ],
        temperature=0,
        max_tokens=16,
    )

    print(f"{model} => {response.choices[0].message.content}")
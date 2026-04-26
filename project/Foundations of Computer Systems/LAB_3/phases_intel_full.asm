
phases.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <phase_1>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   rbp
   5:	48 89 e5             	mov    rbp,rsp
   8:	48 83 ec 20          	sub    rsp,0x20
   c:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  10:	0f b6 05 00 00 00 00 	movzx  eax,BYTE PTR [rip+0x0]        # 17 <phase_1+0x17>
  17:	83 e8 30             	sub    eax,0x30
  1a:	88 45 fb             	mov    BYTE PTR [rbp-0x5],al
  1d:	0f be 45 fb          	movsx  eax,BYTE PTR [rbp-0x5]
  21:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
  24:	8b 55 fc             	mov    edx,DWORD PTR [rbp-0x4]
  27:	48 89 d0             	mov    rax,rdx
  2a:	48 c1 e0 02          	shl    rax,0x2
  2e:	48 01 d0             	add    rax,rdx
  31:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  38:	00 
  39:	48 01 d0             	add    rax,rdx
  3c:	48 01 c0             	add    rax,rax
  3f:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 46 <phase_1+0x46>
  46:	48 01 c2             	add    rdx,rax
  49:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  4d:	48 89 d6             	mov    rsi,rdx
  50:	48 89 c7             	mov    rdi,rax
  53:	e8 00 00 00 00       	call   58 <phase_1+0x58>
  58:	85 c0                	test   eax,eax
  5a:	74 05                	je     61 <phase_1+0x61>
  5c:	e8 00 00 00 00       	call   61 <phase_1+0x61>
  61:	90                   	nop
  62:	c9                   	leave  
  63:	c3                   	ret    

0000000000000064 <phase_2>:
  64:	f3 0f 1e fa          	endbr64 
  68:	55                   	push   rbp
  69:	48 89 e5             	mov    rbp,rsp
  6c:	48 83 ec 40          	sub    rsp,0x40
  70:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
  74:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  7b:	00 00 
  7d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  81:	31 c0                	xor    eax,eax
  83:	48 8d 55 e0          	lea    rdx,[rbp-0x20]
  87:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  8b:	48 89 d6             	mov    rsi,rdx
  8e:	48 89 c7             	mov    rdi,rax
  91:	e8 00 00 00 00       	call   96 <phase_2+0x32>
  96:	8b 45 e0             	mov    eax,DWORD PTR [rbp-0x20]
  99:	85 c0                	test   eax,eax
  9b:	79 05                	jns    a2 <phase_2+0x3e>
  9d:	e8 00 00 00 00       	call   a2 <phase_2+0x3e>
  a2:	8b 45 e0             	mov    eax,DWORD PTR [rbp-0x20]
  a5:	0f b6 15 00 00 00 00 	movzx  edx,BYTE PTR [rip+0x0]        # ac <phase_2+0x48>
  ac:	0f be d2             	movsx  edx,dl
  af:	83 ea 30             	sub    edx,0x30
  b2:	39 d0                	cmp    eax,edx
  b4:	74 05                	je     bb <phase_2+0x57>
  b6:	e8 00 00 00 00       	call   bb <phase_2+0x57>
  bb:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
  be:	0f b6 15 00 00 00 00 	movzx  edx,BYTE PTR [rip+0x0]        # c5 <phase_2+0x61>
  c5:	0f be d2             	movsx  edx,dl
  c8:	83 ea 30             	sub    edx,0x30
  cb:	39 d0                	cmp    eax,edx
  cd:	74 05                	je     d4 <phase_2+0x70>
  cf:	e8 00 00 00 00       	call   d4 <phase_2+0x70>
  d4:	c7 45 dc 02 00 00 00 	mov    DWORD PTR [rbp-0x24],0x2
  db:	eb 33                	jmp    110 <phase_2+0xac>
  dd:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
  e0:	48 98                	cdqe   
  e2:	8b 54 85 e0          	mov    edx,DWORD PTR [rbp+rax*4-0x20]
  e6:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
  e9:	83 e8 01             	sub    eax,0x1
  ec:	48 98                	cdqe   
  ee:	8b 4c 85 e0          	mov    ecx,DWORD PTR [rbp+rax*4-0x20]
  f2:	8b 45 dc             	mov    eax,DWORD PTR [rbp-0x24]
  f5:	83 e8 02             	sub    eax,0x2
  f8:	48 98                	cdqe   
  fa:	8b 44 85 e0          	mov    eax,DWORD PTR [rbp+rax*4-0x20]
  fe:	01 c8                	add    eax,ecx
 100:	83 c0 01             	add    eax,0x1
 103:	39 c2                	cmp    edx,eax
 105:	74 05                	je     10c <phase_2+0xa8>
 107:	e8 00 00 00 00       	call   10c <phase_2+0xa8>
 10c:	83 45 dc 01          	add    DWORD PTR [rbp-0x24],0x1
 110:	83 7d dc 05          	cmp    DWORD PTR [rbp-0x24],0x5
 114:	7e c7                	jle    dd <phase_2+0x79>
 116:	90                   	nop
 117:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 11b:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
 122:	00 00 
 124:	74 05                	je     12b <phase_2+0xc7>
 126:	e8 00 00 00 00       	call   12b <phase_2+0xc7>
 12b:	c9                   	leave  
 12c:	c3                   	ret    

000000000000012d <phase_3>:
 12d:	f3 0f 1e fa          	endbr64 
 131:	55                   	push   rbp
 132:	48 89 e5             	mov    rbp,rsp
 135:	48 83 ec 30          	sub    rsp,0x30
 139:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 13d:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
 144:	00 00 
 146:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 14a:	31 c0                	xor    eax,eax
 14c:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [rbp-0x10],0x0
 153:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [rbp-0xc],0x0
 15a:	48 8d 4d ec          	lea    rcx,[rbp-0x14]
 15e:	48 8d 55 e8          	lea    rdx,[rbp-0x18]
 162:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 166:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 16d <phase_3+0x40>
 16d:	48 89 c7             	mov    rdi,rax
 170:	b8 00 00 00 00       	mov    eax,0x0
 175:	e8 00 00 00 00       	call   17a <phase_3+0x4d>
 17a:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
 17d:	83 7d f4 01          	cmp    DWORD PTR [rbp-0xc],0x1
 181:	7f 05                	jg     188 <phase_3+0x5b>
 183:	e8 00 00 00 00       	call   188 <phase_3+0x5b>
 188:	0f b6 05 00 00 00 00 	movzx  eax,BYTE PTR [rip+0x0]        # 18f <phase_3+0x62>
 18f:	0f be c0             	movsx  eax,al
 192:	8d 50 d0             	lea    edx,[rax-0x30]
 195:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 198:	39 c2                	cmp    edx,eax
 19a:	74 05                	je     1a1 <phase_3+0x74>
 19c:	e8 00 00 00 00       	call   1a1 <phase_3+0x74>
 1a1:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 1a4:	83 f8 09             	cmp    eax,0x9
 1a7:	77 7d                	ja     226 <phase_3+0xf9>
 1a9:	89 c0                	mov    eax,eax
 1ab:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
 1b2:	00 
 1b3:	48 8d 05 00 00 00 00 	lea    rax,[rip+0x0]        # 1ba <phase_3+0x8d>
 1ba:	8b 04 02             	mov    eax,DWORD PTR [rdx+rax*1]
 1bd:	48 98                	cdqe   
 1bf:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 1c6 <phase_3+0x99>
 1c6:	48 01 d0             	add    rax,rdx
 1c9:	3e ff e0             	notrack jmp rax
 1cc:	c7 45 f0 ea 07 00 00 	mov    DWORD PTR [rbp-0x10],0x7ea
 1d3:	eb 56                	jmp    22b <phase_3+0xfe>
 1d5:	c7 45 f0 61 09 00 00 	mov    DWORD PTR [rbp-0x10],0x961
 1dc:	eb 4d                	jmp    22b <phase_3+0xfe>
 1de:	c7 45 f0 7b 00 00 00 	mov    DWORD PTR [rbp-0x10],0x7b
 1e5:	eb 44                	jmp    22b <phase_3+0xfe>
 1e7:	c7 45 f0 8e 02 00 00 	mov    DWORD PTR [rbp-0x10],0x28e
 1ee:	eb 3b                	jmp    22b <phase_3+0xfe>
 1f0:	c7 45 f0 1c 01 00 00 	mov    DWORD PTR [rbp-0x10],0x11c
 1f7:	eb 32                	jmp    22b <phase_3+0xfe>
 1f9:	c7 45 f0 15 03 00 00 	mov    DWORD PTR [rbp-0x10],0x315
 200:	eb 29                	jmp    22b <phase_3+0xfe>
 202:	c7 45 f0 a9 01 00 00 	mov    DWORD PTR [rbp-0x10],0x1a9
 209:	eb 20                	jmp    22b <phase_3+0xfe>
 20b:	c7 45 f0 63 00 00 00 	mov    DWORD PTR [rbp-0x10],0x63
 212:	eb 17                	jmp    22b <phase_3+0xfe>
 214:	c7 45 f0 64 00 00 00 	mov    DWORD PTR [rbp-0x10],0x64
 21b:	eb 0e                	jmp    22b <phase_3+0xfe>
 21d:	c7 45 f0 41 01 00 00 	mov    DWORD PTR [rbp-0x10],0x141
 224:	eb 05                	jmp    22b <phase_3+0xfe>
 226:	e8 00 00 00 00       	call   22b <phase_3+0xfe>
 22b:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
 22e:	39 45 f0             	cmp    DWORD PTR [rbp-0x10],eax
 231:	74 05                	je     238 <phase_3+0x10b>
 233:	e8 00 00 00 00       	call   238 <phase_3+0x10b>
 238:	90                   	nop
 239:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 23d:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
 244:	00 00 
 246:	74 05                	je     24d <phase_3+0x120>
 248:	e8 00 00 00 00       	call   24d <phase_3+0x120>
 24d:	c9                   	leave  
 24e:	c3                   	ret    

000000000000024f <func4>:
 24f:	f3 0f 1e fa          	endbr64 
 253:	55                   	push   rbp
 254:	48 89 e5             	mov    rbp,rsp
 257:	48 83 ec 20          	sub    rsp,0x20
 25b:	89 7d ec             	mov    DWORD PTR [rbp-0x14],edi
 25e:	89 75 e8             	mov    DWORD PTR [rbp-0x18],esi
 261:	89 55 e4             	mov    DWORD PTR [rbp-0x1c],edx
 264:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
 267:	2b 45 e8             	sub    eax,DWORD PTR [rbp-0x18]
 26a:	89 c2                	mov    edx,eax
 26c:	c1 ea 1f             	shr    edx,0x1f
 26f:	01 d0                	add    eax,edx
 271:	d1 f8                	sar    eax,1
 273:	89 c2                	mov    edx,eax
 275:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 278:	01 d0                	add    eax,edx
 27a:	89 45 fc             	mov    DWORD PTR [rbp-0x4],eax
 27d:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 280:	3b 45 ec             	cmp    eax,DWORD PTR [rbp-0x14]
 283:	7e 19                	jle    29e <func4+0x4f>
 285:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 288:	8d 50 ff             	lea    edx,[rax-0x1]
 28b:	8b 4d e8             	mov    ecx,DWORD PTR [rbp-0x18]
 28e:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
 291:	89 ce                	mov    esi,ecx
 293:	89 c7                	mov    edi,eax
 295:	e8 00 00 00 00       	call   29a <func4+0x4b>
 29a:	01 c0                	add    eax,eax
 29c:	eb 29                	jmp    2c7 <func4+0x78>
 29e:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 2a1:	3b 45 ec             	cmp    eax,DWORD PTR [rbp-0x14]
 2a4:	7d 1c                	jge    2c2 <func4+0x73>
 2a6:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 2a9:	8d 48 01             	lea    ecx,[rax+0x1]
 2ac:	8b 55 e4             	mov    edx,DWORD PTR [rbp-0x1c]
 2af:	8b 45 ec             	mov    eax,DWORD PTR [rbp-0x14]
 2b2:	89 ce                	mov    esi,ecx
 2b4:	89 c7                	mov    edi,eax
 2b6:	e8 00 00 00 00       	call   2bb <func4+0x6c>
 2bb:	01 c0                	add    eax,eax
 2bd:	83 c0 01             	add    eax,0x1
 2c0:	eb 05                	jmp    2c7 <func4+0x78>
 2c2:	b8 00 00 00 00       	mov    eax,0x0
 2c7:	c9                   	leave  
 2c8:	c3                   	ret    

00000000000002c9 <phase_4>:
 2c9:	f3 0f 1e fa          	endbr64 
 2cd:	55                   	push   rbp
 2ce:	48 89 e5             	mov    rbp,rsp
 2d1:	48 83 ec 30          	sub    rsp,0x30
 2d5:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 2d9:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
 2e0:	00 00 
 2e2:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 2e6:	31 c0                	xor    eax,eax
 2e8:	48 8d 4d e8          	lea    rcx,[rbp-0x18]
 2ec:	48 8d 55 e4          	lea    rdx,[rbp-0x1c]
 2f0:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 2f4:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 2fb <phase_4+0x32>
 2fb:	48 89 c7             	mov    rdi,rax
 2fe:	b8 00 00 00 00       	mov    eax,0x0
 303:	e8 00 00 00 00       	call   308 <phase_4+0x3f>
 308:	89 45 ec             	mov    DWORD PTR [rbp-0x14],eax
 30b:	83 7d ec 02          	cmp    DWORD PTR [rbp-0x14],0x2
 30f:	75 0f                	jne    320 <phase_4+0x57>
 311:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
 314:	85 c0                	test   eax,eax
 316:	78 08                	js     320 <phase_4+0x57>
 318:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
 31b:	83 f8 0e             	cmp    eax,0xe
 31e:	7e 05                	jle    325 <phase_4+0x5c>
 320:	e8 00 00 00 00       	call   325 <phase_4+0x5c>
 325:	c7 45 f0 07 00 00 00 	mov    DWORD PTR [rbp-0x10],0x7
 32c:	8b 45 e4             	mov    eax,DWORD PTR [rbp-0x1c]
 32f:	ba 0e 00 00 00       	mov    edx,0xe
 334:	be 00 00 00 00       	mov    esi,0x0
 339:	89 c7                	mov    edi,eax
 33b:	e8 00 00 00 00       	call   340 <phase_4+0x77>
 340:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
 343:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
 346:	3b 45 f0             	cmp    eax,DWORD PTR [rbp-0x10]
 349:	75 08                	jne    353 <phase_4+0x8a>
 34b:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 34e:	39 45 f0             	cmp    DWORD PTR [rbp-0x10],eax
 351:	74 05                	je     358 <phase_4+0x8f>
 353:	e8 00 00 00 00       	call   358 <phase_4+0x8f>
 358:	90                   	nop
 359:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 35d:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
 364:	00 00 
 366:	74 05                	je     36d <phase_4+0xa4>
 368:	e8 00 00 00 00       	call   36d <phase_4+0xa4>
 36d:	c9                   	leave  
 36e:	c3                   	ret    

000000000000036f <phase_5>:
 36f:	f3 0f 1e fa          	endbr64 
 373:	55                   	push   rbp
 374:	48 89 e5             	mov    rbp,rsp
 377:	48 83 ec 30          	sub    rsp,0x30
 37b:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 37f:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
 386:	00 00 
 388:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 38c:	31 c0                	xor    eax,eax
 38e:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 392:	48 89 c7             	mov    rdi,rax
 395:	e8 00 00 00 00       	call   39a <phase_5+0x2b>
 39a:	89 45 ec             	mov    DWORD PTR [rbp-0x14],eax
 39d:	83 7d ec 06          	cmp    DWORD PTR [rbp-0x14],0x6
 3a1:	74 05                	je     3a8 <phase_5+0x39>
 3a3:	e8 00 00 00 00       	call   3a8 <phase_5+0x39>
 3a8:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [rbp-0x18],0x0
 3af:	eb 30                	jmp    3e1 <phase_5+0x72>
 3b1:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 3b4:	48 63 d0             	movsxd rdx,eax
 3b7:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 3bb:	48 01 d0             	add    rax,rdx
 3be:	0f b6 00             	movzx  eax,BYTE PTR [rax]
 3c1:	0f be c0             	movsx  eax,al
 3c4:	83 e0 0f             	and    eax,0xf
 3c7:	48 98                	cdqe   
 3c9:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 3d0 <phase_5+0x61>
 3d0:	0f b6 14 10          	movzx  edx,BYTE PTR [rax+rdx*1]
 3d4:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
 3d7:	48 98                	cdqe   
 3d9:	88 54 05 f1          	mov    BYTE PTR [rbp+rax*1-0xf],dl
 3dd:	83 45 e8 01          	add    DWORD PTR [rbp-0x18],0x1
 3e1:	83 7d e8 05          	cmp    DWORD PTR [rbp-0x18],0x5
 3e5:	7e ca                	jle    3b1 <phase_5+0x42>
 3e7:	c6 45 f7 00          	mov    BYTE PTR [rbp-0x9],0x0
 3eb:	48 8d 45 f1          	lea    rax,[rbp-0xf]
 3ef:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 3f6 <phase_5+0x87>
 3f6:	48 89 d6             	mov    rsi,rdx
 3f9:	48 89 c7             	mov    rdi,rax
 3fc:	e8 00 00 00 00       	call   401 <phase_5+0x92>
 401:	85 c0                	test   eax,eax
 403:	74 05                	je     40a <phase_5+0x9b>
 405:	e8 00 00 00 00       	call   40a <phase_5+0x9b>
 40a:	90                   	nop
 40b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 40f:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
 416:	00 00 
 418:	74 05                	je     41f <phase_5+0xb0>
 41a:	e8 00 00 00 00       	call   41f <phase_5+0xb0>
 41f:	c9                   	leave  
 420:	c3                   	ret    

0000000000000421 <phase_6>:
 421:	f3 0f 1e fa          	endbr64 
 425:	55                   	push   rbp
 426:	48 89 e5             	mov    rbp,rsp
 429:	48 81 ec 90 00 00 00 	sub    rsp,0x90
 430:	48 89 bd 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rdi
 437:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
 43e:	00 00 
 440:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 444:	31 c0                	xor    eax,eax
 446:	48 8d 05 00 00 00 00 	lea    rax,[rip+0x0]        # 44d <phase_6+0x2c>
 44d:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
 451:	48 8d 55 a0          	lea    rdx,[rbp-0x60]
 455:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
 45c:	48 89 d6             	mov    rsi,rdx
 45f:	48 89 c7             	mov    rdi,rax
 462:	e8 00 00 00 00       	call   467 <phase_6+0x46>
 467:	c7 45 88 00 00 00 00 	mov    DWORD PTR [rbp-0x78],0x0
 46e:	eb 54                	jmp    4c4 <phase_6+0xa3>
 470:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 473:	48 98                	cdqe   
 475:	8b 44 85 a0          	mov    eax,DWORD PTR [rbp+rax*4-0x60]
 479:	85 c0                	test   eax,eax
 47b:	7e 0e                	jle    48b <phase_6+0x6a>
 47d:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 480:	48 98                	cdqe   
 482:	8b 44 85 a0          	mov    eax,DWORD PTR [rbp+rax*4-0x60]
 486:	83 f8 06             	cmp    eax,0x6
 489:	7e 05                	jle    490 <phase_6+0x6f>
 48b:	e8 00 00 00 00       	call   490 <phase_6+0x6f>
 490:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 493:	83 c0 01             	add    eax,0x1
 496:	89 45 8c             	mov    DWORD PTR [rbp-0x74],eax
 499:	eb 1f                	jmp    4ba <phase_6+0x99>
 49b:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 49e:	48 98                	cdqe   
 4a0:	8b 54 85 a0          	mov    edx,DWORD PTR [rbp+rax*4-0x60]
 4a4:	8b 45 8c             	mov    eax,DWORD PTR [rbp-0x74]
 4a7:	48 98                	cdqe   
 4a9:	8b 44 85 a0          	mov    eax,DWORD PTR [rbp+rax*4-0x60]
 4ad:	39 c2                	cmp    edx,eax
 4af:	75 05                	jne    4b6 <phase_6+0x95>
 4b1:	e8 00 00 00 00       	call   4b6 <phase_6+0x95>
 4b6:	83 45 8c 01          	add    DWORD PTR [rbp-0x74],0x1
 4ba:	83 7d 8c 05          	cmp    DWORD PTR [rbp-0x74],0x5
 4be:	7e db                	jle    49b <phase_6+0x7a>
 4c0:	83 45 88 01          	add    DWORD PTR [rbp-0x78],0x1
 4c4:	83 7d 88 05          	cmp    DWORD PTR [rbp-0x78],0x5
 4c8:	7e a6                	jle    470 <phase_6+0x4f>
 4ca:	c7 45 88 00 00 00 00 	mov    DWORD PTR [rbp-0x78],0x0
 4d1:	eb 41                	jmp    514 <phase_6+0xf3>
 4d3:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
 4d7:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 4db:	c7 45 8c 01 00 00 00 	mov    DWORD PTR [rbp-0x74],0x1
 4e2:	eb 10                	jmp    4f4 <phase_6+0xd3>
 4e4:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 4e8:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
 4ec:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 4f0:	83 45 8c 01          	add    DWORD PTR [rbp-0x74],0x1
 4f4:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 4f7:	48 98                	cdqe   
 4f9:	8b 44 85 a0          	mov    eax,DWORD PTR [rbp+rax*4-0x60]
 4fd:	39 45 8c             	cmp    DWORD PTR [rbp-0x74],eax
 500:	7c e2                	jl     4e4 <phase_6+0xc3>
 502:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 505:	48 98                	cdqe   
 507:	48 8b 55 90          	mov    rdx,QWORD PTR [rbp-0x70]
 50b:	48 89 54 c5 c0       	mov    QWORD PTR [rbp+rax*8-0x40],rdx
 510:	83 45 88 01          	add    DWORD PTR [rbp-0x78],0x1
 514:	83 7d 88 05          	cmp    DWORD PTR [rbp-0x78],0x5
 518:	7e b9                	jle    4d3 <phase_6+0xb2>
 51a:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
 51e:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
 522:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
 526:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 52a:	c7 45 88 01 00 00 00 	mov    DWORD PTR [rbp-0x78],0x1
 531:	eb 22                	jmp    555 <phase_6+0x134>
 533:	8b 45 88             	mov    eax,DWORD PTR [rbp-0x78]
 536:	48 98                	cdqe   
 538:	48 8b 54 c5 c0       	mov    rdx,QWORD PTR [rbp+rax*8-0x40]
 53d:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 541:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
 545:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 549:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
 54d:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 551:	83 45 88 01          	add    DWORD PTR [rbp-0x78],0x1
 555:	83 7d 88 05          	cmp    DWORD PTR [rbp-0x78],0x5
 559:	7e d8                	jle    533 <phase_6+0x112>
 55b:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 55f:	48 c7 40 08 00 00 00 	mov    QWORD PTR [rax+0x8],0x0
 566:	00 
 567:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
 56b:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 56f:	c7 45 88 00 00 00 00 	mov    DWORD PTR [rbp-0x78],0x0
 576:	eb 29                	jmp    5a1 <phase_6+0x180>
 578:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 57c:	8b 10                	mov    edx,DWORD PTR [rax]
 57e:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 582:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
 586:	8b 00                	mov    eax,DWORD PTR [rax]
 588:	39 c2                	cmp    edx,eax
 58a:	7d 05                	jge    591 <phase_6+0x170>
 58c:	e8 00 00 00 00       	call   591 <phase_6+0x170>
 591:	48 8b 45 90          	mov    rax,QWORD PTR [rbp-0x70]
 595:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
 599:	48 89 45 90          	mov    QWORD PTR [rbp-0x70],rax
 59d:	83 45 88 01          	add    DWORD PTR [rbp-0x78],0x1
 5a1:	83 7d 88 04          	cmp    DWORD PTR [rbp-0x78],0x4
 5a5:	7e d1                	jle    578 <phase_6+0x157>
 5a7:	90                   	nop
 5a8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 5ac:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
 5b3:	00 00 
 5b5:	74 05                	je     5bc <phase_6+0x19b>
 5b7:	e8 00 00 00 00       	call   5bc <phase_6+0x19b>
 5bc:	c9                   	leave  
 5bd:	c3                   	ret    

00000000000005be <fun7>:
 5be:	f3 0f 1e fa          	endbr64 
 5c2:	55                   	push   rbp
 5c3:	48 89 e5             	mov    rbp,rsp
 5c6:	48 83 ec 10          	sub    rsp,0x10
 5ca:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
 5ce:	89 75 f4             	mov    DWORD PTR [rbp-0xc],esi
 5d1:	48 83 7d f8 00       	cmp    QWORD PTR [rbp-0x8],0x0
 5d6:	75 07                	jne    5df <fun7+0x21>
 5d8:	b8 ff ff ff ff       	mov    eax,0xffffffff
 5dd:	eb 50                	jmp    62f <fun7+0x71>
 5df:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 5e3:	8b 00                	mov    eax,DWORD PTR [rax]
 5e5:	39 45 f4             	cmp    DWORD PTR [rbp-0xc],eax
 5e8:	7d 19                	jge    603 <fun7+0x45>
 5ea:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 5ee:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
 5f2:	8b 55 f4             	mov    edx,DWORD PTR [rbp-0xc]
 5f5:	89 d6                	mov    esi,edx
 5f7:	48 89 c7             	mov    rdi,rax
 5fa:	e8 00 00 00 00       	call   5ff <fun7+0x41>
 5ff:	01 c0                	add    eax,eax
 601:	eb 2c                	jmp    62f <fun7+0x71>
 603:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 607:	8b 00                	mov    eax,DWORD PTR [rax]
 609:	39 45 f4             	cmp    DWORD PTR [rbp-0xc],eax
 60c:	75 07                	jne    615 <fun7+0x57>
 60e:	b8 00 00 00 00       	mov    eax,0x0
 613:	eb 1a                	jmp    62f <fun7+0x71>
 615:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 619:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
 61d:	8b 55 f4             	mov    edx,DWORD PTR [rbp-0xc]
 620:	89 d6                	mov    esi,edx
 622:	48 89 c7             	mov    rdi,rax
 625:	e8 00 00 00 00       	call   62a <fun7+0x6c>
 62a:	01 c0                	add    eax,eax
 62c:	83 c0 01             	add    eax,0x1
 62f:	c9                   	leave  
 630:	c3                   	ret    

Disassembly of section .data:

0000000000000000 <special>:
   0:	57                   	push   rdi
   1:	65 6c                	gs ins BYTE PTR es:[rdi],dx
   3:	63 6f 6d             	movsxd ebp,DWORD PTR [rdi+0x6d]
   6:	65 20 74 6f 20       	and    BYTE PTR gs:[rdi+rbp*2+0x20],dh
   b:	64 65 66 75 73       	fs gs data16 jne 83 <special+0x83>
  10:	65 20 74 68 65       	and    BYTE PTR gs:[rax+rbp*2+0x65],dh
  15:	20 62 6f             	and    BYTE PTR [rdx+0x6f],ah
  18:	6d                   	ins    DWORD PTR es:[rdi],dx
  19:	62 73 2e 00 00       	(bad)
	...
  32:	49 53                	rex.WB push r11
  34:	41 20 49 6e          	and    BYTE PTR [r9+0x6e],cl
  38:	73 74                	jae    ae <special+0xae>
  3a:	72 75                	jb     b1 <special+0xb1>
  3c:	63 74 69 6f          	movsxd esi,DWORD PTR [rcx+rbp*2+0x6f]
  40:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  41:	20 53 65             	and    BYTE PTR [rbx+0x65],dl
  44:	74 20                	je     66 <special+0x66>
  46:	41 72 63             	rex.B jb ac <special+0xac>
  49:	68 69 74 65 63       	push   0x63657469
  4e:	74 75                	je     c5 <special+0xc5>
  50:	72 65                	jb     b7 <special+0xb7>
  52:	2e 00 00             	cs add BYTE PTR [rax],al
	...
  61:	00 00                	add    BYTE PTR [rax],al
  63:	00 41 42             	add    BYTE PTR [rcx+0x42],al
  66:	49 20 41 70          	rex.WB and BYTE PTR [r9+0x70],al
  6a:	70 6c                	jo     d8 <special+0xd8>
  6c:	69 63 61 74 69 6f 6e 	imul   esp,DWORD PTR [rbx+0x61],0x6e6f6974
  73:	20 42 69             	and    BYTE PTR [rdx+0x69],al
  76:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  77:	61                   	(bad)  
  78:	72 79                	jb     f3 <special+0xf3>
  7a:	20 49 6e             	and    BYTE PTR [rcx+0x6e],cl
  7d:	74 65                	je     e4 <special+0xe4>
  7f:	72 66                	jb     e7 <special+0xe7>
  81:	61                   	(bad)  
  82:	63 65 2e             	movsxd esp,DWORD PTR [rbp+0x2e]
	...
  95:	00 41 50             	add    BYTE PTR [rcx+0x50],al
  98:	49 20 41 70          	rex.WB and BYTE PTR [r9+0x70],al
  9c:	70 6c                	jo     10a <special+0x10a>
  9e:	69 63 61 74 69 6f 6e 	imul   esp,DWORD PTR [rbx+0x61],0x6e6f6974
  a5:	20 50 72             	and    BYTE PTR [rax+0x72],dl
  a8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  a9:	67 72 61             	addr32 jb 10d <special+0x10d>
  ac:	6d                   	ins    DWORD PTR es:[rdi],dx
  ad:	6d                   	ins    DWORD PTR es:[rdi],dx
  ae:	69 6e 67 20 49 6e 74 	imul   ebp,DWORD PTR [rsi+0x67],0x746e4920
  b5:	65 72 66             	gs jb  11e <special+0x11e>
  b8:	61                   	(bad)  
  b9:	63 65 2e             	movsxd esp,DWORD PTR [rbp+0x2e]
	...
  c8:	44 69 73 61 73 73 65 	imul   r14d,DWORD PTR [rbx+0x61],0x6d657373
  cf:	6d 
  d0:	62                   	(bad)  
  d1:	6c                   	ins    BYTE PTR es:[rdi],dx
  d2:	79 2e                	jns    102 <special+0x102>
	...
  f8:	00 00                	add    BYTE PTR [rax],al
  fa:	52                   	push   rdx
  fb:	65 6c                	gs ins BYTE PTR es:[rdi],dx
  fd:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  fe:	63 61 74             	movsxd esp,DWORD PTR [rcx+0x74]
 101:	61                   	(bad)  
 102:	62                   	(bad)  
 103:	6c                   	ins    BYTE PTR es:[rdi],dx
 104:	65 20 4f 62          	and    BYTE PTR gs:[rdi+0x62],cl
 108:	6a 65                	push   0x65
 10a:	63 74 20 46          	movsxd esi,DWORD PTR [rax+riz*1+0x46]
 10e:	69 6c 65 00 00 00 00 	imul   ebp,DWORD PTR [rbp+riz*2+0x0],0x0
 115:	00 
	...
 12a:	00 00                	add    BYTE PTR [rax],al
 12c:	45 78 65             	rex.RB js 194 <special+0x194>
 12f:	63 75 74             	movsxd esi,DWORD PTR [rbp+0x74]
 132:	61                   	(bad)  
 133:	62                   	(bad)  
 134:	6c                   	ins    BYTE PTR es:[rdi],dx
 135:	65 20 4f 62          	and    BYTE PTR gs:[rdi+0x62],cl
 139:	6a 65                	push   0x65
 13b:	63 74 20 46          	movsxd esi,DWORD PTR [rax+riz*1+0x46]
 13f:	69 6c 65 00 00 00 00 	imul   ebp,DWORD PTR [rbp+riz*2+0x0],0x0
 146:	00 
	...
 15b:	00 00                	add    BYTE PTR [rax],al
 15d:	00 41 73             	add    BYTE PTR [rcx+0x73],al
 160:	73 65                	jae    1c7 <special+0x1c7>
 162:	6d                   	ins    DWORD PTR es:[rdi],dx
 163:	62                   	(bad)  
 164:	6c                   	ins    BYTE PTR es:[rdi],dx
 165:	65 20 4c 61 6e       	and    BYTE PTR gs:[rcx+riz*2+0x6e],cl
 16a:	67 75 61             	addr32 jne 1ce <special+0x1ce>
 16d:	67 65 00 00          	add    BYTE PTR gs:[eax],al
	...
 18d:	00 00                	add    BYTE PTR [rax],al
 18f:	00 43 6f             	add    BYTE PTR [rbx+0x6f],al
 192:	6d                   	ins    DWORD PTR es:[rdi],dx
 193:	70 75                	jo     20a <node6+0xa>
 195:	74 65                	je     1fc <special+0x1fc>
 197:	72 20                	jb     1b9 <special+0x1b9>
 199:	53                   	push   rbx
 19a:	79 73                	jns    20f <node6+0xf>
 19c:	74 65                	je     203 <node6+0x3>
 19e:	6d                   	ins    DWORD PTR es:[rdi],dx
 19f:	20 46 6f             	and    BYTE PTR [rsi+0x6f],al
 1a2:	75 6e                	jne    212 <n48+0x2>
 1a4:	64 61                	fs (bad) 
 1a6:	74 69                	je     211 <n48+0x1>
 1a8:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 1a9:	6e                   	outs   dx,BYTE PTR ds:[rsi]
	...
 1c2:	4f 70 65             	rex.WRXB jo 22a <n48+0x1a>
 1c5:	72 61                	jb     228 <n48+0x18>
 1c7:	74 69                	je     232 <n46+0x2>
 1c9:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 1ca:	67 20 53 79          	and    BYTE PTR [ebx+0x79],dl
 1ce:	73 74                	jae    244 <n46+0x14>
 1d0:	65 6d                	gs ins DWORD PTR es:[rdi],dx
	...

0000000000000200 <node6>:
 200:	10 02                	adc    BYTE PTR [rdx],al
 202:	00 00                	add    BYTE PTR [rax],al
 204:	06                   	(bad)  
	...

0000000000000210 <n48>:
 210:	e9 03 00 00 00       	jmp    218 <n48+0x8>
	...

0000000000000230 <n46>:
 230:	2f                   	(bad)  
	...

0000000000000250 <n43>:
 250:	14 00                	adc    al,0x0
	...

0000000000000270 <n42>:
 270:	07                   	(bad)  
	...

0000000000000290 <n44>:
 290:	23 00                	and    eax,DWORD PTR [rax]
	...

00000000000002b0 <n47>:
 2b0:	63 00                	movsxd eax,DWORD PTR [rax]
	...

00000000000002d0 <n41>:
 2d0:	01 00                	add    DWORD PTR [rax],eax
	...

00000000000002f0 <n45>:
 2f0:	28 00                	sub    BYTE PTR [rax],al
	...

0000000000000310 <array.0>:
 310:	6d                   	ins    DWORD PTR es:[rdi],dx
 311:	61                   	(bad)  
 312:	64 75 69             	fs jne 37e <phase_5+0xf>
 315:	65 72 73             	gs jb  38b <phase_5+0x1c>
 318:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 319:	66 6f                	outs   dx,WORD PTR ds:[rsi]
 31b:	74 76                	je     393 <phase_5+0x24>
 31d:	62                   	.byte 0x62
 31e:	79 6c                	jns    38c <phase_5+0x1d>

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	25 64 20 25 64       	and    eax,0x64252064
	...
  2d:	00 00                	add    BYTE PTR [rax],al
  2f:	00 62 72             	add    BYTE PTR [rdx+0x72],ah
  32:	75 69                	jne    9d <n33+0xd>
  34:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  35:	73 00                	jae    37 <node2+0x7>

Disassembly of section .data.rel.local:

0000000000000000 <node5>:
   0:	38 03                	cmp    BYTE PTR [rbx],al
   2:	00 00                	add    BYTE PTR [rax],al
   4:	05 00 00 00 00       	add    eax,0x0
   9:	00 00                	add    BYTE PTR [rax],al
   b:	00 00                	add    BYTE PTR [rax],al
   d:	00 00                	add    BYTE PTR [rax],al
	...

0000000000000010 <node4>:
  10:	79 00                	jns    12 <node4+0x2>
  12:	00 00                	add    BYTE PTR [rax],al
  14:	04 00                	add    al,0x0
	...

0000000000000020 <node3>:
  20:	42 01 00             	rex.X add DWORD PTR [rax],eax
  23:	00 03                	add    BYTE PTR [rbx],al
	...

0000000000000030 <node2>:
  30:	8b 03                	mov    eax,DWORD PTR [rbx]
  32:	00 00                	add    BYTE PTR [rax],al
  34:	02 00                	add    al,BYTE PTR [rax]
	...

0000000000000040 <node1>:
  40:	19 01                	sbb    DWORD PTR [rcx],eax
  42:	00 00                	add    BYTE PTR [rax],al
  44:	01 00                	add    DWORD PTR [rax],eax
	...

0000000000000050 <n34>:
  50:	6b 00 00             	imul   eax,DWORD PTR [rax],0x0
	...

0000000000000070 <n31>:
  70:	06                   	(bad)  
	...

0000000000000090 <n33>:
  90:	2d 00 00 00 00       	sub    eax,0x0
	...

00000000000000b0 <n32>:
  b0:	16                   	(bad)  
	...

00000000000000d0 <n22>:
  d0:	32 00                	xor    al,BYTE PTR [rax]
	...

00000000000000f0 <n21>:
  f0:	08 00                	or     BYTE PTR [rax],al
	...

0000000000000110 <n1>:
 110:	24 00                	and    al,0x0
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    BYTE PTR [rdi+0x43],al
   3:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   6:	28 55 62             	sub    BYTE PTR [rbp+0x62],dl
   9:	75 6e                	jne    79 <n31+0x9>
   b:	74 75                	je     82 <n31+0x12>
   d:	20 31                	and    BYTE PTR [rcx],dh
   f:	31 2e                	xor    DWORD PTR [rsi],ebp
  11:	34 2e                	xor    al,0x2e
  13:	30 2d 31 75 62 75    	xor    BYTE PTR [rip+0x75627531],ch        # 7562754a <fun7+0x75626f8c>
  19:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  1a:	74 75                	je     91 <n33+0x1>
  1c:	31 7e 32             	xor    DWORD PTR [rsi+0x32],edi
  1f:	32 2e                	xor    ch,BYTE PTR [rsi]
  21:	30 34 2e             	xor    BYTE PTR [rsi+rbp*1],dh
  24:	33 29                	xor    ebp,DWORD PTR [rcx]
  26:	20 31                	and    BYTE PTR [rcx],dh
  28:	31 2e                	xor    DWORD PTR [rsi],ebp
  2a:	34 2e                	xor    al,0x2e
  2c:	30 00                	xor    BYTE PTR [rax],al

Disassembly of section .note.gnu.property:

0000000000000000 <.note.gnu.property>:
   0:	04 00                	add    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	10 00                	adc    BYTE PTR [rax],al
   6:	00 00                	add    BYTE PTR [rax],al
   8:	05 00 00 00 47       	add    eax,0x47000000
   d:	4e 55                	rex.WRX push rbp
   f:	00 02                	add    BYTE PTR [rdx],al
  11:	00 00                	add    BYTE PTR [rax],al
  13:	c0 04 00 00          	rol    BYTE PTR [rax+rax*1],0x0
  17:	00 03                	add    BYTE PTR [rbx],al
  19:	00 00                	add    BYTE PTR [rax],al
  1b:	00 00                	add    BYTE PTR [rax],al
  1d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	00 00                	add    BYTE PTR [rax],al
   6:	00 00                	add    BYTE PTR [rax],al
   8:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
   b:	00 01                	add    BYTE PTR [rcx],al
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    DWORD PTR [rbx],ebx
  11:	0c 07                	or     al,0x7
  13:	08 90 01 00 00 1c    	or     BYTE PTR [rax+0x1c000001],dl
  19:	00 00                	add    BYTE PTR [rax],al
  1b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  1e:	00 00                	add    BYTE PTR [rax],al
  20:	00 00                	add    BYTE PTR [rax],al
  22:	00 00                	add    BYTE PTR [rax],al
  24:	64 00 00             	add    BYTE PTR fs:[rax],al
  27:	00 00                	add    BYTE PTR [rax],al
  29:	45 0e                	rex.RB (bad) 
  2b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  31:	02 5b 0c             	add    bl,BYTE PTR [rbx+0xc]
  34:	07                   	(bad)  
  35:	08 00                	or     BYTE PTR [rax],al
  37:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  3a:	00 00                	add    BYTE PTR [rax],al
  3c:	3c 00                	cmp    al,0x0
  3e:	00 00                	add    BYTE PTR [rax],al
  40:	00 00                	add    BYTE PTR [rax],al
  42:	00 00                	add    BYTE PTR [rax],al
  44:	c9                   	leave  
  45:	00 00                	add    BYTE PTR [rax],al
  47:	00 00                	add    BYTE PTR [rax],al
  49:	45 0e                	rex.RB (bad) 
  4b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  51:	02 c0                	add    al,al
  53:	0c 07                	or     al,0x7
  55:	08 00                	or     BYTE PTR [rax],al
  57:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  5a:	00 00                	add    BYTE PTR [rax],al
  5c:	5c                   	pop    rsp
  5d:	00 00                	add    BYTE PTR [rax],al
  5f:	00 00                	add    BYTE PTR [rax],al
  61:	00 00                	add    BYTE PTR [rax],al
  63:	00 22                	add    BYTE PTR [rdx],ah
  65:	01 00                	add    DWORD PTR [rax],eax
  67:	00 00                	add    BYTE PTR [rax],al
  69:	45 0e                	rex.RB (bad) 
  6b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  71:	03 19                	add    ebx,DWORD PTR [rcx]
  73:	01 0c 07             	add    DWORD PTR [rdi+rax*1],ecx
  76:	08 00                	or     BYTE PTR [rax],al
  78:	1c 00                	sbb    al,0x0
  7a:	00 00                	add    BYTE PTR [rax],al
  7c:	7c 00                	jl     7e <.eh_frame+0x7e>
  7e:	00 00                	add    BYTE PTR [rax],al
  80:	00 00                	add    BYTE PTR [rax],al
  82:	00 00                	add    BYTE PTR [rax],al
  84:	7a 00                	jp     86 <.eh_frame+0x86>
  86:	00 00                	add    BYTE PTR [rax],al
  88:	00 45 0e             	add    BYTE PTR [rbp+0xe],al
  8b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  91:	02 71 0c             	add    dh,BYTE PTR [rcx+0xc]
  94:	07                   	(bad)  
  95:	08 00                	or     BYTE PTR [rax],al
  97:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  9a:	00 00                	add    BYTE PTR [rax],al
  9c:	9c                   	pushf  
  9d:	00 00                	add    BYTE PTR [rax],al
  9f:	00 00                	add    BYTE PTR [rax],al
  a1:	00 00                	add    BYTE PTR [rax],al
  a3:	00 a6 00 00 00 00    	add    BYTE PTR [rsi+0x0],ah
  a9:	45 0e                	rex.RB (bad) 
  ab:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  b1:	02 9d 0c 07 08 00    	add    bl,BYTE PTR [rbp+0x8070c]
  b7:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  ba:	00 00                	add    BYTE PTR [rax],al
  bc:	bc 00 00 00 00       	mov    esp,0x0
  c1:	00 00                	add    BYTE PTR [rax],al
  c3:	00 b2 00 00 00 00    	add    BYTE PTR [rdx+0x0],dh
  c9:	45 0e                	rex.RB (bad) 
  cb:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  d1:	02 a9 0c 07 08 00    	add    ch,BYTE PTR [rcx+0x8070c]
  d7:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
  da:	00 00                	add    BYTE PTR [rax],al
  dc:	dc 00                	fadd   QWORD PTR [rax]
  de:	00 00                	add    BYTE PTR [rax],al
  e0:	00 00                	add    BYTE PTR [rax],al
  e2:	00 00                	add    BYTE PTR [rax],al
  e4:	9d                   	popf   
  e5:	01 00                	add    DWORD PTR [rax],eax
  e7:	00 00                	add    BYTE PTR [rax],al
  e9:	45 0e                	rex.RB (bad) 
  eb:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
  f1:	03 94 01 0c 07 08 00 	add    edx,DWORD PTR [rcx+rax*1+0x8070c]
  f8:	1c 00                	sbb    al,0x0
  fa:	00 00                	add    BYTE PTR [rax],al
  fc:	fc                   	cld    
  fd:	00 00                	add    BYTE PTR [rax],al
  ff:	00 00                	add    BYTE PTR [rax],al
 101:	00 00                	add    BYTE PTR [rax],al
 103:	00 73 00             	add    BYTE PTR [rbx+0x0],dh
 106:	00 00                	add    BYTE PTR [rax],al
 108:	00 45 0e             	add    BYTE PTR [rbp+0xe],al
 10b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
 111:	02 6a 0c             	add    ch,BYTE PTR [rdx+0xc]
 114:	07                   	(bad)  
 115:	08 00                	or     BYTE PTR [rax],al
	...

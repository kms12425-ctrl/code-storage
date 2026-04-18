.686P
.model flat, c
printf proto c :ptr sbyte, :vararg
; includelib  libcmt.lib
includelib  legacy_stdio_definitions.lib 

student  struct
    sname   db   8 dup(0)
    sid     db   11 dup(0)
    align   2    ; 指明对齐方式，汇编语言默认是紧凑存放
                 ; 可以实验一下，去掉对齐方式伪指令的结果
    scores  dw   8  dup(0)
    average dw   0
student   ends

.data
   lpfmt  db "%s %s %d %d",0dh,0ah,0
   lpfmt_string  db "%s  ",0
   lpfmt_num  db "%d  ",0
   lpfmt_size    db  "size of struct %d  ",0dh,0ah,0
   lpfmt_offset  db  0dh,0ah,"offset of scores %d  ",0dh,0ah,0

.code
;  显示学生信息
;  sptr 学生数组的首地址
;  num  学生人数
;  注意， printf 中会用到一些寄存器，也没有保护
;         即执行 printf前后，一个寄存器中的内容发生变化

display proc  sptr: dword, num:dword
        local  i:dword      ; 定义局部变量，等同 unsigned int

        mov  ebx, sptr
        invoke printf, offset lpfmt_string, ebx
        invoke printf, offset lpfmt_string, addr  [ebx].student.sid

        invoke printf , offset lpfmt_num,  [ebx].student.scores[0]   ; 第0个分数
        invoke printf , offset lpfmt_num,  [ebx].student.scores[2]   ; 第1个分数
        add   ebx, 24
        invoke printf , offset lpfmt_num,  word ptr [ebx]    ; 第2个分数

        mov    esi, offset student.scores  ; 取字段scores 在结构中的偏移量
        mov    edi, type student           ; 取结构的大小
        invoke printf , offset lpfmt_offset, esi
        invoke printf , offset lpfmt_size, edi

        mov    ebx,num         ; 局部变量、参数的用法示例
        mov    i,  ebx
        invoke printf, offset lpfmt_num, i   ; 显示学生人数

        ret
display endp

computeAverageScore proc uses ebx esi edi, sptr: dword, num:dword
    ;ebx=当前student *
    ;esi=剩余学生数量
    ;edi=scores 下标偏移
    ;eax/edx/ecx = 计算用

    mov ebx, sptr
    mov esi, num
    test esi, esi
    jle done_students

student_loop:
    xor edx, edx ;sum
    xor edi, edi ;成绩下标

score_loop:
    movsx eax, word ptr [ebx].student.scores[edi]
    add edx, eax
    add edi, 2
    cmp edi, 16
    jl score_loop
    mov eax, edx
    cdq
    mov ecx,8
    idiv ecx
    mov [ebx].student.average,ax

    add ebx, type student
    dec esi
    jnz student_loop

done_students:
    ret

computeAverageScore endp

computeAverageScore_improve proc uses edi ecx edx, sptr:dword, num:dword
    ; edi = 当前 student*
    ; ecx = 剩余学生数
    ; eax = sum / avg
    ; edx = 临时寄存器

    mov edi, sptr
    mov ecx, num
    test ecx, ecx
    jle done_students

student_loop:
    xor eax, eax

    movzx edx, word ptr [edi].student.scores[0]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[2]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[4]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[6]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[8]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[10]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[12]
    add eax, edx
    movzx edx, word ptr [edi].student.scores[14]
    add eax, edx

    shr eax, 3
    mov [edi].student.average, ax

    add edi, type student
    dec ecx
    jnz student_loop

done_students:
    ret

computeAverageScore_improve endp
end
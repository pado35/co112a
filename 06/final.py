dest = {
    '':    '000', 'M':   '001', 'D':   '010', 'DM':  '011', 
    'A':   '100', 'AM':  '101', 'DM':  '110', 'ADM': '111'
}

comp = {
    '0':   '0101010', '1':   '0111111', '-1':  '0111010', 'D':   '0001100',
    'A':   '0110000', '!D':  '0001101', '!A':  '0110001', '-D':  '0001111',
    '-A':  '0110011', 'D+1': '0011111', 'A+1': '0110111', 'D-1': '0001110',
    'A-1': '0110010', 'D+A': '0000010', 'D-A': '0010011', 'A-D': '0000111',
    'D&A': '0000000', 'D|A': '0010101', 'M':   '1110000', '!M':  '1110001',
    '-M':  '1110011', 'M+1': '1110111', 'M-1': '1110010', 'D+M': '1000010',
    'D-M': '1010011', 'M-D': '1000111', 'D&M': '1000000', 'D|M': '1010101'
}

jump = {
    '':'000', 'JGT':'001', 'JEQ':'010', 'JGE':'011',
    'JLT':'100', 'LNE':'101', 'JLE':'110', 'JMP':'111', 
}
pos = {'SCREEN':'16384', 'KBD':'24576'}
for i in range(0,16):
    pos['R'+str(i)] = i

#command = str(input('輸入指令:'))
sourse = open('input.asm', 'r')
destination = open('output.hack', 'w')
count = -1
for command in sourse:
    if command == '\n':
        continue
    command = command.split()[0].rstrip('\n')
    if command[0] == '/':
        continue
    count += 1
    if command[0] == '(':
        pos[command.strip('()\n')] = count
        count -= 1
#print(pos)

sourse.seek(0)
for command in sourse:
    if command == '\n':
        continue
    command = command.split()[0].rstrip('\n')
    if command[0] == '/' or command[0] == '(':
        continue

    if(command[0] == '@'):
        command = command.replace(command[0], '')
        if not(command.isdigit()):
            if command not in pos:
                i+=1
                pos[command] = i
            command = pos[command]
        output = f'{int(command):016b}'
    else:
        output = '111'
        EqualIndex = command.find('=')
        JumpIndex = command.find(';')
        if JumpIndex ==-1:
            JumpIndex=len(command)
        
        #D = A         =..end
        #    D ; jmp   0..;
        #A = D ; jmp   =..;
        output += comp[command[EqualIndex+1:JumpIndex]]
        if(EqualIndex == -1):
            EqualIndex = 0
        output += dest[command[0:EqualIndex]]
        output += jump[command[JumpIndex+1:]]
    destination.write(output + '\n')
sourse.close
destination.close
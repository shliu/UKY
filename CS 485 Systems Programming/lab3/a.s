
a.out:     file format elf32-i386


Disassembly of section .init:

080483a4 <_init>:
 80483a4:	53                   	push   %ebx
 80483a5:	83 ec 08             	sub    $0x8,%esp
 80483a8:	e8 f3 00 00 00       	call   80484a0 <__x86.get_pc_thunk.bx>
 80483ad:	81 c3 53 1c 00 00    	add    $0x1c53,%ebx
 80483b3:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80483b9:	85 c0                	test   %eax,%eax
 80483bb:	74 05                	je     80483c2 <_init+0x1e>
 80483bd:	e8 3e 00 00 00       	call   8048400 <__gmon_start__@plt>
 80483c2:	83 c4 08             	add    $0x8,%esp
 80483c5:	5b                   	pop    %ebx
 80483c6:	c3                   	ret    

Disassembly of section .plt:

080483d0 <strcmp@plt-0x10>:
 80483d0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80483d6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80483dc:	00 00                	add    %al,(%eax)
	...

080483e0 <strcmp@plt>:
 80483e0:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 80483e6:	68 00 00 00 00       	push   $0x0
 80483eb:	e9 e0 ff ff ff       	jmp    80483d0 <_init+0x2c>

080483f0 <puts@plt>:
 80483f0:	ff 25 10 a0 04 08    	jmp    *0x804a010
 80483f6:	68 08 00 00 00       	push   $0x8
 80483fb:	e9 d0 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048400 <__gmon_start__@plt>:
 8048400:	ff 25 14 a0 04 08    	jmp    *0x804a014
 8048406:	68 10 00 00 00       	push   $0x10
 804840b:	e9 c0 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048410 <exit@plt>:
 8048410:	ff 25 18 a0 04 08    	jmp    *0x804a018
 8048416:	68 18 00 00 00       	push   $0x18
 804841b:	e9 b0 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048420 <__libc_start_main@plt>:
 8048420:	ff 25 1c a0 04 08    	jmp    *0x804a01c
 8048426:	68 20 00 00 00       	push   $0x20
 804842b:	e9 a0 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048430 <putchar@plt>:
 8048430:	ff 25 20 a0 04 08    	jmp    *0x804a020
 8048436:	68 28 00 00 00       	push   $0x28
 804843b:	e9 90 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048440 <__printf_chk@plt>:
 8048440:	ff 25 24 a0 04 08    	jmp    *0x804a024
 8048446:	68 30 00 00 00       	push   $0x30
 804844b:	e9 80 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048450 <__gets_chk@plt>:
 8048450:	ff 25 28 a0 04 08    	jmp    *0x804a028
 8048456:	68 38 00 00 00       	push   $0x38
 804845b:	e9 70 ff ff ff       	jmp    80483d0 <_init+0x2c>

08048460 <__sprintf_chk@plt>:
 8048460:	ff 25 2c a0 04 08    	jmp    *0x804a02c
 8048466:	68 40 00 00 00       	push   $0x40
 804846b:	e9 60 ff ff ff       	jmp    80483d0 <_init+0x2c>

Disassembly of section .text:

08048470 <_start>:
 8048470:	31 ed                	xor    %ebp,%ebp
 8048472:	5e                   	pop    %esi
 8048473:	89 e1                	mov    %esp,%ecx
 8048475:	83 e4 f0             	and    $0xfffffff0,%esp
 8048478:	50                   	push   %eax
 8048479:	54                   	push   %esp
 804847a:	52                   	push   %edx
 804847b:	68 00 87 04 08       	push   $0x8048700
 8048480:	68 90 86 04 08       	push   $0x8048690
 8048485:	51                   	push   %ecx
 8048486:	56                   	push   %esi
 8048487:	68 6d 85 04 08       	push   $0x804856d
 804848c:	e8 8f ff ff ff       	call   8048420 <__libc_start_main@plt>
 8048491:	f4                   	hlt    
 8048492:	66 90                	xchg   %ax,%ax
 8048494:	66 90                	xchg   %ax,%ax
 8048496:	66 90                	xchg   %ax,%ax
 8048498:	66 90                	xchg   %ax,%ax
 804849a:	66 90                	xchg   %ax,%ax
 804849c:	66 90                	xchg   %ax,%ax
 804849e:	66 90                	xchg   %ax,%ax

080484a0 <__x86.get_pc_thunk.bx>:
 80484a0:	8b 1c 24             	mov    (%esp),%ebx
 80484a3:	c3                   	ret    
 80484a4:	66 90                	xchg   %ax,%ax
 80484a6:	66 90                	xchg   %ax,%ax
 80484a8:	66 90                	xchg   %ax,%ax
 80484aa:	66 90                	xchg   %ax,%ax
 80484ac:	66 90                	xchg   %ax,%ax
 80484ae:	66 90                	xchg   %ax,%ax

080484b0 <deregister_tm_clones>:
 80484b0:	b8 3b a0 04 08       	mov    $0x804a03b,%eax
 80484b5:	2d 38 a0 04 08       	sub    $0x804a038,%eax
 80484ba:	83 f8 06             	cmp    $0x6,%eax
 80484bd:	77 01                	ja     80484c0 <deregister_tm_clones+0x10>
 80484bf:	c3                   	ret    
 80484c0:	b8 00 00 00 00       	mov    $0x0,%eax
 80484c5:	85 c0                	test   %eax,%eax
 80484c7:	74 f6                	je     80484bf <deregister_tm_clones+0xf>
 80484c9:	55                   	push   %ebp
 80484ca:	89 e5                	mov    %esp,%ebp
 80484cc:	83 ec 18             	sub    $0x18,%esp
 80484cf:	c7 04 24 38 a0 04 08 	movl   $0x804a038,(%esp)
 80484d6:	ff d0                	call   *%eax
 80484d8:	c9                   	leave  
 80484d9:	c3                   	ret    
 80484da:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

080484e0 <register_tm_clones>:
 80484e0:	b8 38 a0 04 08       	mov    $0x804a038,%eax
 80484e5:	2d 38 a0 04 08       	sub    $0x804a038,%eax
 80484ea:	c1 f8 02             	sar    $0x2,%eax
 80484ed:	89 c2                	mov    %eax,%edx
 80484ef:	c1 ea 1f             	shr    $0x1f,%edx
 80484f2:	01 d0                	add    %edx,%eax
 80484f4:	d1 f8                	sar    %eax
 80484f6:	75 01                	jne    80484f9 <register_tm_clones+0x19>
 80484f8:	c3                   	ret    
 80484f9:	ba 00 00 00 00       	mov    $0x0,%edx
 80484fe:	85 d2                	test   %edx,%edx
 8048500:	74 f6                	je     80484f8 <register_tm_clones+0x18>
 8048502:	55                   	push   %ebp
 8048503:	89 e5                	mov    %esp,%ebp
 8048505:	83 ec 18             	sub    $0x18,%esp
 8048508:	89 44 24 04          	mov    %eax,0x4(%esp)
 804850c:	c7 04 24 38 a0 04 08 	movl   $0x804a038,(%esp)
 8048513:	ff d2                	call   *%edx
 8048515:	c9                   	leave  
 8048516:	c3                   	ret    
 8048517:	89 f6                	mov    %esi,%esi
 8048519:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048520 <__do_global_dtors_aux>:
 8048520:	80 3d 38 a0 04 08 00 	cmpb   $0x0,0x804a038
 8048527:	75 13                	jne    804853c <__do_global_dtors_aux+0x1c>
 8048529:	55                   	push   %ebp
 804852a:	89 e5                	mov    %esp,%ebp
 804852c:	83 ec 08             	sub    $0x8,%esp
 804852f:	e8 7c ff ff ff       	call   80484b0 <deregister_tm_clones>
 8048534:	c6 05 38 a0 04 08 01 	movb   $0x1,0x804a038
 804853b:	c9                   	leave  
 804853c:	f3 c3                	repz ret 
 804853e:	66 90                	xchg   %ax,%ax

08048540 <frame_dummy>:
 8048540:	a1 10 9f 04 08       	mov    0x8049f10,%eax
 8048545:	85 c0                	test   %eax,%eax
 8048547:	74 1f                	je     8048568 <frame_dummy+0x28>
 8048549:	b8 00 00 00 00       	mov    $0x0,%eax
 804854e:	85 c0                	test   %eax,%eax
 8048550:	74 16                	je     8048568 <frame_dummy+0x28>
 8048552:	55                   	push   %ebp
 8048553:	89 e5                	mov    %esp,%ebp
 8048555:	83 ec 18             	sub    $0x18,%esp
 8048558:	c7 04 24 10 9f 04 08 	movl   $0x8049f10,(%esp)
 804855f:	ff d0                	call   *%eax
 8048561:	c9                   	leave  
 8048562:	e9 79 ff ff ff       	jmp    80484e0 <register_tm_clones>
 8048567:	90                   	nop
 8048568:	e9 73 ff ff ff       	jmp    80484e0 <register_tm_clones>

0804856d <main>:
 804856d:	55                   	push   %ebp
 804856e:	89 e5                	mov    %esp,%ebp
 8048570:	56                   	push   %esi
 8048571:	53                   	push   %ebx
 8048572:	83 e4 f0             	and    $0xfffffff0,%esp
 8048575:	81 ec b0 01 00 00    	sub    $0x1b0,%esp
 804857b:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048581:	89 84 24 ac 01 00 00 	mov    %eax,0x1ac(%esp)
 8048588:	31 c0                	xor    %eax,%eax
 804858a:	c7 05 3c a0 04 08 0e 	movl   $0x10e,0x804a03c
 8048591:	01 00 00 
 8048594:	c7 44 24 04 20 87 04 	movl   $0x8048720,0x4(%esp)	//"Please enter the magic phrase: "
 804859b:	08 
 804859c:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 80485a3:	e8 98 fe ff ff       	call   8048440 <__printf_chk@plt>
 80485a8:	c7 44 24 04 80 00 00 	movl   $0x80,0x4(%esp)
 80485af:	00 
 80485b0:	8d 5c 24 2c          	lea    0x2c(%esp),%ebx
 80485b4:	89 1c 24             	mov    %ebx,(%esp)
 80485b7:	e8 94 fe ff ff       	call   8048450 <__gets_chk@plt>
 80485bc:	c7 04 24 0a 00 00 00 	movl   $0xa,(%esp)
 80485c3:	e8 68 fe ff ff       	call   8048430 <putchar@plt>
 80485c8:	89 5c 24 14          	mov    %ebx,0x14(%esp)
 80485cc:	a1 3c a0 04 08       	mov    0x804a03c,%eax
 80485d1:	89 44 24 10          	mov    %eax,0x10(%esp)
 80485d5:	c7 44 24 0c 48 87 04 	movl   $0x8048748,0xc(%esp) //Your CS %d pass phrase was '%s'\n
 80485dc:	08 
 80485dd:	c7 44 24 08 80 00 00 	movl   $0x80,0x8(%esp)
 80485e4:	00 
 80485e5:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 80485ec:	00 
 80485ed:	8d b4 24 ac 00 00 00 	lea    0xac(%esp),%esi
 80485f4:	89 34 24             	mov    %esi,(%esp)
 80485f7:	e8 64 fe ff ff       	call   8048460 <__sprintf_chk@plt>
 80485fc:	c7 44 24 14 6c 87 04 	movl   $0x804876c,0x14(%esp) //GDB will really help with systems programming!
 8048603:	08 
 8048604:	a1 3c a0 04 08       	mov    0x804a03c,%eax
 8048609:	89 44 24 10          	mov    %eax,0x10(%esp)
 804860d:	c7 44 24 0c 48 87 04 	movl   $0x8048748,0xc(%esp) //Your CS %d pass phrase was '%s'\n
 8048614:	08 
 8048615:	c7 44 24 08 80 00 00 	movl   $0x80,0x8(%esp)
 804861c:	00 
 804861d:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8048624:	00 
 8048625:	8d 9c 24 2c 01 00 00 	lea    0x12c(%esp),%ebx
 804862c:	89 1c 24             	mov    %ebx,(%esp)
 804862f:	e8 2c fe ff ff       	call   8048460 <__sprintf_chk@plt>
 8048634:	89 74 24 04          	mov    %esi,0x4(%esp)
 8048638:	89 1c 24             	mov    %ebx,(%esp)
 804863b:	e8 a0 fd ff ff       	call   80483e0 <strcmp@plt>
 8048640:	85 c0                	test   %eax,%eax
 8048642:	75 27                	jne    804866b <main+0xfe>
 8048644:	c7 04 24 9c 87 04 08 	movl   $0x804879c,(%esp) //Congrats.  You discovered the pass phrase!
 804864b:	e8 a0 fd ff ff       	call   80483f0 <puts@plt>
 8048650:	8d 84 24 ac 00 00 00 	lea    0xac(%esp),%eax
 8048657:	89 04 24             	mov    %eax,(%esp)
 804865a:	e8 91 fd ff ff       	call   80483f0 <puts@plt>
 804865f:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048666:	e8 a5 fd ff ff       	call   8048410 <exit@plt>
 804866b:	c7 04 24 c8 87 04 08 	movl   $0x80487c8,(%esp) //Sorry.  That pass phrase is incorrect.
 8048672:	e8 79 fd ff ff       	call   80483f0 <puts@plt>
 8048677:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 804867e:	e8 8d fd ff ff       	call   8048410 <exit@plt>

08048683 <proginit>:
 8048683:	c7 05 3c a0 04 08 0e 	movl   $0x10e,0x804a03c
 804868a:	01 00 00 
 804868d:	c3                   	ret    
 804868e:	66 90                	xchg   %ax,%ax

08048690 <__libc_csu_init>:
 8048690:	55                   	push   %ebp
 8048691:	57                   	push   %edi
 8048692:	31 ff                	xor    %edi,%edi
 8048694:	56                   	push   %esi
 8048695:	53                   	push   %ebx
 8048696:	e8 05 fe ff ff       	call   80484a0 <__x86.get_pc_thunk.bx>
 804869b:	81 c3 65 19 00 00    	add    $0x1965,%ebx
 80486a1:	83 ec 1c             	sub    $0x1c,%esp
 80486a4:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 80486a8:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 80486ae:	e8 f1 fc ff ff       	call   80483a4 <_init>
 80486b3:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 80486b9:	29 c6                	sub    %eax,%esi
 80486bb:	c1 fe 02             	sar    $0x2,%esi
 80486be:	85 f6                	test   %esi,%esi
 80486c0:	74 27                	je     80486e9 <__libc_csu_init+0x59>
 80486c2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 80486c8:	8b 44 24 38          	mov    0x38(%esp),%eax
 80486cc:	89 2c 24             	mov    %ebp,(%esp)
 80486cf:	89 44 24 08          	mov    %eax,0x8(%esp)
 80486d3:	8b 44 24 34          	mov    0x34(%esp),%eax
 80486d7:	89 44 24 04          	mov    %eax,0x4(%esp)
 80486db:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 80486e2:	83 c7 01             	add    $0x1,%edi
 80486e5:	39 f7                	cmp    %esi,%edi
 80486e7:	75 df                	jne    80486c8 <__libc_csu_init+0x38>
 80486e9:	83 c4 1c             	add    $0x1c,%esp
 80486ec:	5b                   	pop    %ebx
 80486ed:	5e                   	pop    %esi
 80486ee:	5f                   	pop    %edi
 80486ef:	5d                   	pop    %ebp
 80486f0:	c3                   	ret    
 80486f1:	eb 0d                	jmp    8048700 <__libc_csu_fini>
 80486f3:	90                   	nop
 80486f4:	90                   	nop
 80486f5:	90                   	nop
 80486f6:	90                   	nop
 80486f7:	90                   	nop
 80486f8:	90                   	nop
 80486f9:	90                   	nop
 80486fa:	90                   	nop
 80486fb:	90                   	nop
 80486fc:	90                   	nop
 80486fd:	90                   	nop
 80486fe:	90                   	nop
 80486ff:	90                   	nop

08048700 <__libc_csu_fini>:
 8048700:	f3 c3                	repz ret 

Disassembly of section .fini:

08048704 <_fini>:
 8048704:	53                   	push   %ebx
 8048705:	83 ec 08             	sub    $0x8,%esp
 8048708:	e8 93 fd ff ff       	call   80484a0 <__x86.get_pc_thunk.bx>
 804870d:	81 c3 f3 18 00 00    	add    $0x18f3,%ebx
 8048713:	83 c4 08             	add    $0x8,%esp
 8048716:	5b                   	pop    %ebx
 8048717:	c3                   	ret    

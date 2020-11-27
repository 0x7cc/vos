//
// Created by xxx on 2020/11/22.
//

#ifndef vSVM_H
#define vSVM_H

#include "vos.h"
#include "npt.h"

//
// See "SVM Intercept Codes"
//
#define VMEXIT_CR0_READ 0x0000
#define VMEXIT_CR1_READ 0x0001
#define VMEXIT_CR2_READ 0x0002
#define VMEXIT_CR3_READ 0x0003
#define VMEXIT_CR4_READ 0x0004
#define VMEXIT_CR5_READ 0x0005
#define VMEXIT_CR6_READ 0x0006
#define VMEXIT_CR7_READ 0x0007
#define VMEXIT_CR8_READ 0x0008
#define VMEXIT_CR9_READ 0x0009
#define VMEXIT_CR10_READ 0x000a
#define VMEXIT_CR11_READ 0x000b
#define VMEXIT_CR12_READ 0x000c
#define VMEXIT_CR13_READ 0x000d
#define VMEXIT_CR14_READ 0x000e
#define VMEXIT_CR15_READ 0x000f
#define VMEXIT_CR0_WRITE 0x0010
#define VMEXIT_CR1_WRITE 0x0011
#define VMEXIT_CR2_WRITE 0x0012
#define VMEXIT_CR3_WRITE 0x0013
#define VMEXIT_CR4_WRITE 0x0014
#define VMEXIT_CR5_WRITE 0x0015
#define VMEXIT_CR6_WRITE 0x0016
#define VMEXIT_CR7_WRITE 0x0017
#define VMEXIT_CR8_WRITE 0x0018
#define VMEXIT_CR9_WRITE 0x0019
#define VMEXIT_CR10_WRITE 0x001a
#define VMEXIT_CR11_WRITE 0x001b
#define VMEXIT_CR12_WRITE 0x001c
#define VMEXIT_CR13_WRITE 0x001d
#define VMEXIT_CR14_WRITE 0x001e
#define VMEXIT_CR15_WRITE 0x001f
#define VMEXIT_DR0_READ 0x0020
#define VMEXIT_DR1_READ 0x0021
#define VMEXIT_DR2_READ 0x0022
#define VMEXIT_DR3_READ 0x0023
#define VMEXIT_DR4_READ 0x0024
#define VMEXIT_DR5_READ 0x0025
#define VMEXIT_DR6_READ 0x0026
#define VMEXIT_DR7_READ 0x0027
#define VMEXIT_DR8_READ 0x0028
#define VMEXIT_DR9_READ 0x0029
#define VMEXIT_DR10_READ 0x002a
#define VMEXIT_DR11_READ 0x002b
#define VMEXIT_DR12_READ 0x002c
#define VMEXIT_DR13_READ 0x002d
#define VMEXIT_DR14_READ 0x002e
#define VMEXIT_DR15_READ 0x002f
#define VMEXIT_DR0_WRITE 0x0030
#define VMEXIT_DR1_WRITE 0x0031
#define VMEXIT_DR2_WRITE 0x0032
#define VMEXIT_DR3_WRITE 0x0033
#define VMEXIT_DR4_WRITE 0x0034
#define VMEXIT_DR5_WRITE 0x0035
#define VMEXIT_DR6_WRITE 0x0036
#define VMEXIT_DR7_WRITE 0x0037
#define VMEXIT_DR8_WRITE 0x0038
#define VMEXIT_DR9_WRITE 0x0039
#define VMEXIT_DR10_WRITE 0x003a
#define VMEXIT_DR11_WRITE 0x003b
#define VMEXIT_DR12_WRITE 0x003c
#define VMEXIT_DR13_WRITE 0x003d
#define VMEXIT_DR14_WRITE 0x003e
#define VMEXIT_DR15_WRITE 0x003f
#define VMEXIT_EXCEPTION_DE 0x0040
#define VMEXIT_EXCEPTION_DB 0x0041
#define VMEXIT_EXCEPTION_NMI 0x0042
#define VMEXIT_EXCEPTION_BP 0x0043
#define VMEXIT_EXCEPTION_OF 0x0044
#define VMEXIT_EXCEPTION_BR 0x0045
#define VMEXIT_EXCEPTION_UD 0x0046
#define VMEXIT_EXCEPTION_NM 0x0047
#define VMEXIT_EXCEPTION_DF 0x0048
#define VMEXIT_EXCEPTION_09 0x0049
#define VMEXIT_EXCEPTION_TS 0x004a
#define VMEXIT_EXCEPTION_NP 0x004b
#define VMEXIT_EXCEPTION_SS 0x004c
#define VMEXIT_EXCEPTION_GP 0x004d
#define VMEXIT_EXCEPTION_PF 0x004e
#define VMEXIT_EXCEPTION_15 0x004f
#define VMEXIT_EXCEPTION_MF 0x0050
#define VMEXIT_EXCEPTION_AC 0x0051
#define VMEXIT_EXCEPTION_MC 0x0052
#define VMEXIT_EXCEPTION_XF 0x0053
#define VMEXIT_EXCEPTION_20 0x0054
#define VMEXIT_EXCEPTION_21 0x0055
#define VMEXIT_EXCEPTION_22 0x0056
#define VMEXIT_EXCEPTION_23 0x0057
#define VMEXIT_EXCEPTION_24 0x0058
#define VMEXIT_EXCEPTION_25 0x0059
#define VMEXIT_EXCEPTION_26 0x005a
#define VMEXIT_EXCEPTION_27 0x005b
#define VMEXIT_EXCEPTION_28 0x005c
#define VMEXIT_EXCEPTION_VC 0x005d
#define VMEXIT_EXCEPTION_SX 0x005e
#define VMEXIT_EXCEPTION_31 0x005f
#define VMEXIT_INTR 0x0060
#define VMEXIT_NMI 0x0061
#define VMEXIT_SMI 0x0062
#define VMEXIT_INIT 0x0063
#define VMEXIT_VINTR 0x0064
#define VMEXIT_CR0_SEL_WRITE 0x0065
#define VMEXIT_IDTR_READ 0x0066
#define VMEXIT_GDTR_READ 0x0067
#define VMEXIT_LDTR_READ 0x0068
#define VMEXIT_TR_READ 0x0069
#define VMEXIT_IDTR_WRITE 0x006a
#define VMEXIT_GDTR_WRITE 0x006b
#define VMEXIT_LDTR_WRITE 0x006c
#define VMEXIT_TR_WRITE 0x006d
#define VMEXIT_RDTSC 0x006e
#define VMEXIT_RDPMC 0x006f
#define VMEXIT_PUSHF 0x0070
#define VMEXIT_POPF 0x0071
#define VMEXIT_CPUID 0x0072
#define VMEXIT_RSM 0x0073
#define VMEXIT_IRET 0x0074
#define VMEXIT_SWINT 0x0075
#define VMEXIT_INVD 0x0076
#define VMEXIT_PAUSE 0x0077
#define VMEXIT_HLT 0x0078
#define VMEXIT_INVLPG 0x0079
#define VMEXIT_INVLPGA 0x007a
#define VMEXIT_IOIO 0x007b
#define VMEXIT_MSR 0x007c
#define VMEXIT_TASK_SWITCH 0x007d
#define VMEXIT_FERR_FREEZE 0x007e
#define VMEXIT_SHUTDOWN 0x007f
#define VMEXIT_VMRUN 0x0080
#define VMEXIT_VMMCALL 0x0081
#define VMEXIT_VMLOAD 0x0082
#define VMEXIT_VMSAVE 0x0083
#define VMEXIT_STGI 0x0084
#define VMEXIT_CLGI 0x0085
#define VMEXIT_SKINIT 0x0086
#define VMEXIT_RDTSCP 0x0087
#define VMEXIT_ICEBP 0x0088
#define VMEXIT_WBINVD 0x0089
#define VMEXIT_MONITOR 0x008a
#define VMEXIT_MWAIT 0x008b
#define VMEXIT_MWAIT_CONDITIONAL 0x008c
#define VMEXIT_XSETBV 0x008d
#define VMEXIT_EFER_WRITE_TRAP 0x008f
#define VMEXIT_CR0_WRITE_TRAP 0x0090
#define VMEXIT_CR1_WRITE_TRAP 0x0091
#define VMEXIT_CR2_WRITE_TRAP 0x0092
#define VMEXIT_CR3_WRITE_TRAP 0x0093
#define VMEXIT_CR4_WRITE_TRAP 0x0094
#define VMEXIT_CR5_WRITE_TRAP 0x0095
#define VMEXIT_CR6_WRITE_TRAP 0x0096
#define VMEXIT_CR7_WRITE_TRAP 0x0097
#define VMEXIT_CR8_WRITE_TRAP 0x0098
#define VMEXIT_CR9_WRITE_TRAP 0x0099
#define VMEXIT_CR10_WRITE_TRAP 0x009a
#define VMEXIT_CR11_WRITE_TRAP 0x009b
#define VMEXIT_CR12_WRITE_TRAP 0x009c
#define VMEXIT_CR13_WRITE_TRAP 0x009d
#define VMEXIT_CR14_WRITE_TRAP 0x009e
#define VMEXIT_CR15_WRITE_TRAP 0x009f
#define VMEXIT_NPF 0x0400
#define AVIC_INCOMPLETE_IPI 0x0401
#define AVIC_NOACCEL 0x0402
#define VMEXIT_VMGEXIT 0x0403
#define VMEXIT_INVALID -1

typedef struct _VMCB_CONTROL_AREA {
  vuint16 InterceptCrRead;            // +0x000
  vuint16 InterceptCrWrite;           // +0x002
  vuint16 InterceptDrRead;            // +0x004
  vuint16 InterceptDrWrite;           // +0x006
  vuint32 InterceptException;         // +0x008
  vuint32 InterceptMisc1;             // +0x00c
  vuint32 InterceptMisc2;             // +0x010
  vuint8  Reserved1[0x03c - 0x014];   // +0x014
  vuint16 PauseFilterThreshold;       // +0x03c
  vuint16 PauseFilterCount;           // +0x03e
  vuint64 IopmBasePa;                 // +0x040
  vuint64 MsrpmBasePa;                // +0x048
  vuint64 TscOffset;                  // +0x050
  vuint32 GuestAsid;                  // +0x058
  vuint32 TlbControl;                 // +0x05c
  vuint64 VIntr;                      // +0x060
  vuint64 InterruptShadow;            // +0x068
  vuint64 ExitCode;                   // +0x070
  vuint64 ExitInfo1;                  // +0x078
  vuint64 ExitInfo2;                  // +0x080
  vuint64 ExitIntInfo;                // +0x088
  vuint64 NpEnable;                   // +0x090
  vuint64 AvicApicBar;                // +0x098
  vuint64 GuestPaOfGhcb;              // +0x0a0
  vuint64 EventInj;                   // +0x0a8
  vuint64 NCr3;                       // +0x0b0
  vuint64 LbrVirtualizationEnable;    // +0x0b8
  vuint64 VmcbClean;                  // +0x0c0
  vuint64 NRip;                       // +0x0c8
  vuint8  NumOfBytesFetched;          // +0x0d0
  vuint8  GuestInstructionBytes[15];  // +0x0d1
  vuint64 AvicApicBackingPagePointer; // +0x0e0
  vuint64 Reserved2;                  // +0x0e8
  vuint64 AvicLogicalTablePointer;    // +0x0f0
  vuint64 AvicPhysicalTablePointer;   // +0x0f8
  vuint64 Reserved3;                  // +0x100
  vuint64 VmcbSaveStatePointer;       // +0x108
  vuint8  Reserved4[0x400 - 0x110];   // +0x110
} VMCB_CONTROL_AREA, *PVMCB_CONTROL_AREA;
static_assert (sizeof (VMCB_CONTROL_AREA) == 0x400, "");

//
// See "VMCB Layout, State Save Area"
//
typedef struct _VMCB_STATE_SAVE_AREA {
  vuint16 EsSelector;               // +0x000
  vuint16 EsAttrib;                 // +0x002
  vuint32 EsLimit;                  // +0x004
  vuint64 EsBase;                   // +0x008
  vuint16 CsSelector;               // +0x010
  vuint16 CsAttrib;                 // +0x012
  vuint32 CsLimit;                  // +0x014
  vuint64 CsBase;                   // +0x018
  vuint16 SsSelector;               // +0x020
  vuint16 SsAttrib;                 // +0x022
  vuint32 SsLimit;                  // +0x024
  vuint64 SsBase;                   // +0x028
  vuint16 DsSelector;               // +0x030
  vuint16 DsAttrib;                 // +0x032
  vuint32 DsLimit;                  // +0x034
  vuint64 DsBase;                   // +0x038
  vuint16 FsSelector;               // +0x040
  vuint16 FsAttrib;                 // +0x042
  vuint32 FsLimit;                  // +0x044
  vuint64 FsBase;                   // +0x048
  vuint16 GsSelector;               // +0x050
  vuint16 GsAttrib;                 // +0x052
  vuint32 GsLimit;                  // +0x054
  vuint64 GsBase;                   // +0x058
  vuint16 GdtrSelector;             // +0x060
  vuint16 GdtrAttrib;               // +0x062
  vuint32 GdtrLimit;                // +0x064
  vuint64 GdtrBase;                 // +0x068
  vuint16 LdtrSelector;             // +0x070
  vuint16 LdtrAttrib;               // +0x072
  vuint32 LdtrLimit;                // +0x074
  vuint64 LdtrBase;                 // +0x078
  vuint16 IdtrSelector;             // +0x080
  vuint16 IdtrAttrib;               // +0x082
  vuint32 IdtrLimit;                // +0x084
  vuint64 IdtrBase;                 // +0x088
  vuint16 TrSelector;               // +0x090
  vuint16 TrAttrib;                 // +0x092
  vuint32 TrLimit;                  // +0x094
  vuint64 TrBase;                   // +0x098
  vuint8  Reserved1[0x0cb - 0x0a0]; // +0x0a0
  vuint8  Cpl;                      // +0x0cb
  vuint32 Reserved2;                // +0x0cc
  vuint64 Efer;                     // +0x0d0
  vuint8  Reserved3[0x148 - 0x0d8]; // +0x0d8
  vuint64 Cr4;                      // +0x148
  vuint64 Cr3;                      // +0x150
  vuint64 Cr0;                      // +0x158
  vuint64 Dr7;                      // +0x160
  vuint64 Dr6;                      // +0x168
  vuint64 Rflags;                   // +0x170
  vuint64 Rip;                      // +0x178
  vuint8  Reserved4[0x1d8 - 0x180]; // +0x180
  vuint64 Rsp;                      // +0x1d8
  vuint8  Reserved5[0x1f8 - 0x1e0]; // +0x1e0
  vuint64 Rax;                      // +0x1f8
  vuint64 Star;                     // +0x200
  vuint64 LStar;                    // +0x208
  vuint64 CStar;                    // +0x210
  vuint64 SfMask;                   // +0x218
  vuint64 KernelGsBase;             // +0x220
  vuint64 SysenterCs;               // +0x228
  vuint64 SysenterEsp;              // +0x230
  vuint64 SysenterEip;              // +0x238
  vuint64 Cr2;                      // +0x240
  vuint8  Reserved6[0x268 - 0x248]; // +0x248
  vuint64 GPat;                     // +0x268
  vuint64 DbgCtl;                   // +0x270
  vuint64 BrFrom;                   // +0x278
  vuint64 BrTo;                     // +0x280
  vuint64 LastExcepFrom;            // +0x288
  vuint64 LastExcepTo;              // +0x290
} VMCB_STATE_SAVE_AREA, *PVMCB_STATE_SAVE_AREA;
static_assert (sizeof (VMCB_STATE_SAVE_AREA) == 0x298, "");

//
// An entire VMCB (Virtual machine control block) layout.
//
typedef struct
{
  VMCB_CONTROL_AREA    ControlArea;
  VMCB_STATE_SAVE_AREA StateSaveArea;
  vuint8               Reserved1[0x1000 - sizeof (VMCB_CONTROL_AREA) - sizeof (VMCB_STATE_SAVE_AREA)];
} VMCB, *PVMCB;
static_assert (sizeof (VMCB) == 0x1000, "");

typedef struct svmcontext svmcontext;

int svm_load (svmcontext**);
int svm_unload (svmcontext**);
int svm_luanch (svmcontext*);

typedef struct
{
  vuint64 rax;
  vuint64 rbx;
  vuint64 rcx;
  vuint64 rdx;
  vuint64 rsi;
  vuint64 rdi;
  vuint64 r8;
  vuint64 r9;
  vuint64 r10;
  vuint64 r11;
  vuint64 r12;
  vuint64 r13;
  vuint64 r14;
  vuint64 r15;
  vuint64 flags;
  vuint64 vmcbptr;
} SvmVMExitContext;

#endif //vSVM_H

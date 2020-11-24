//
// Created by xxx on 2020/11/22.
//

#ifndef vVMX_H
#define vVMX_H

#include "vos.h"
#include "ept.h"

// clang-format off

/** 16-bit control fields.  */
#define VMX_VMCS16_VPID                                         0x0000
#define VMX_VMCS16_POSTED_INT_NOTIFY_VECTOR                     0x0002
#define VMX_VMCS16_EPTP_INDEX                                   0x0004

/** 16-bit guest-state fields.  */
#define VMX_VMCS16_GUEST_ES_SEL                                 0x0800
#define VMX_VMCS16_GUEST_CS_SEL                                 0x0802
#define VMX_VMCS16_GUEST_SS_SEL                                 0x0804
#define VMX_VMCS16_GUEST_DS_SEL                                 0x0806
#define VMX_VMCS16_GUEST_FS_SEL                                 0x0808
#define VMX_VMCS16_GUEST_GS_SEL                                 0x080a
#define VMX_VMCS16_GUEST_LDTR_SEL                               0x080c
#define VMX_VMCS16_GUEST_TR_SEL                                 0x080e
#define VMX_VMCS16_GUEST_INTR_STATUS                            0x0810
#define VMX_VMCS16_GUEST_PML_INDEX                              0x0812

/** 16-bits host-state fields.  */
#define VMX_VMCS16_HOST_ES_SEL                                  0x0c00
#define VMX_VMCS16_HOST_CS_SEL                                  0x0c02
#define VMX_VMCS16_HOST_SS_SEL                                  0x0c04
#define VMX_VMCS16_HOST_DS_SEL                                  0x0c06
#define VMX_VMCS16_HOST_FS_SEL                                  0x0c08
#define VMX_VMCS16_HOST_GS_SEL                                  0x0c0a
#define VMX_VMCS16_HOST_TR_SEL                                  0x0c0c

/** 64-bit control fields. */
#define VMX_VMCS64_CTRL_IO_BITMAP_A_FULL                        0x2000
#define VMX_VMCS64_CTRL_IO_BITMAP_A_HIGH                        0x2001
#define VMX_VMCS64_CTRL_IO_BITMAP_B_FULL                        0x2002
#define VMX_VMCS64_CTRL_IO_BITMAP_B_HIGH                        0x2003
#define VMX_VMCS64_CTRL_MSR_BITMAP_FULL                         0x2004
#define VMX_VMCS64_CTRL_MSR_BITMAP_HIGH                         0x2005
#define VMX_VMCS64_CTRL_EXIT_MSR_STORE_FULL                     0x2006
#define VMX_VMCS64_CTRL_EXIT_MSR_STORE_HIGH                     0x2007
#define VMX_VMCS64_CTRL_EXIT_MSR_LOAD_FULL                      0x2008
#define VMX_VMCS64_CTRL_EXIT_MSR_LOAD_HIGH                      0x2009
#define VMX_VMCS64_CTRL_ENTRY_MSR_LOAD_FULL                     0x200a
#define VMX_VMCS64_CTRL_ENTRY_MSR_LOAD_HIGH                     0x200b
#define VMX_VMCS64_CTRL_EXEC_VMCS_PTR_FULL                      0x200c
#define VMX_VMCS64_CTRL_EXEC_VMCS_PTR_HIGH                      0x200d
#define VMX_VMCS64_CTRL_EXEC_PML_ADDR_FULL                      0x200e
#define VMX_VMCS64_CTRL_EXEC_PML_ADDR_HIGH                      0x200f
#define VMX_VMCS64_CTRL_TSC_OFFSET_FULL                         0x2010
#define VMX_VMCS64_CTRL_TSC_OFFSET_HIGH                         0x2011
#define VMX_VMCS64_CTRL_VIRT_APIC_PAGEADDR_FULL                 0x2012
#define VMX_VMCS64_CTRL_VIRT_APIC_PAGEADDR_HIGH                 0x2013
#define VMX_VMCS64_CTRL_APIC_ACCESSADDR_FULL                    0x2014
#define VMX_VMCS64_CTRL_APIC_ACCESSADDR_HIGH                    0x2015
#define VMX_VMCS64_CTRL_POSTED_INTR_DESC_FULL                   0x2016
#define VMX_VMCS64_CTRL_POSTED_INTR_DESC_HIGH                   0x2017
#define VMX_VMCS64_CTRL_VMFUNC_CTRLS_FULL                       0x2018
#define VMX_VMCS64_CTRL_VMFUNC_CTRLS_HIGH                       0x2019
#define VMX_VMCS64_CTRL_EPTP_FULL                               0x201a
#define VMX_VMCS64_CTRL_EPTP_HIGH                               0x201b
#define VMX_VMCS64_CTRL_EOI_BITMAP_0_FULL                       0x201c
#define VMX_VMCS64_CTRL_EOI_BITMAP_0_HIGH                       0x201d
#define VMX_VMCS64_CTRL_EOI_BITMAP_1_FULL                       0x201e
#define VMX_VMCS64_CTRL_EOI_BITMAP_1_HIGH                       0x201f
#define VMX_VMCS64_CTRL_EOI_BITMAP_2_FULL                       0x2020
#define VMX_VMCS64_CTRL_EOI_BITMAP_2_HIGH                       0x2021
#define VMX_VMCS64_CTRL_EOI_BITMAP_3_FULL                       0x2022
#define VMX_VMCS64_CTRL_EOI_BITMAP_3_HIGH                       0x2023
#define VMX_VMCS64_CTRL_EPTP_LIST_FULL                          0x2024
#define VMX_VMCS64_CTRL_EPTP_LIST_HIGH                          0x2025
#define VMX_VMCS64_CTRL_VMREAD_BITMAP_FULL                      0x2026
#define VMX_VMCS64_CTRL_VMREAD_BITMAP_HIGH                      0x2027
#define VMX_VMCS64_CTRL_VMWRITE_BITMAP_FULL                     0x2028
#define VMX_VMCS64_CTRL_VMWRITE_BITMAP_HIGH                     0x2029
#define VMX_VMCS64_CTRL_VIRTXCPT_INFO_ADDR_FULL                 0x202a
#define VMX_VMCS64_CTRL_VIRTXCPT_INFO_ADDR_HIGH                 0x202b
#define VMX_VMCS64_CTRL_XSS_EXITING_BITMAP_FULL                 0x202c
#define VMX_VMCS64_CTRL_XSS_EXITING_BITMAP_HIGH                 0x202d
#define VMX_VMCS64_CTRL_ENCLS_EXITING_BITMAP_FULL               0x202e
#define VMX_VMCS64_CTRL_ENCLS_EXITING_BITMAP_HIGH               0x202f
#define VMX_VMCS64_CTRL_TSC_MULTIPLIER_FULL                     0x2032
#define VMX_VMCS64_CTRL_TSC_MULTIPLIER_HIGH                     0x2033

/** 64-bit read-only data fields.  */
#define VMX_VMCS64_RO_GUEST_PHYS_ADDR_FULL                      0x2400
#define VMX_VMCS64_RO_GUEST_PHYS_ADDR_HIGH                      0x2401

/** 64-bit guest-state fields.  */
#define VMX_VMCS64_GUEST_VMCS_LINK_PTR_FULL                     0x2800
#define VMX_VMCS64_GUEST_VMCS_LINK_PTR_HIGH                     0x2801
#define VMX_VMCS64_GUEST_DEBUGCTL_FULL                          0x2802
#define VMX_VMCS64_GUEST_DEBUGCTL_HIGH                          0x2803
#define VMX_VMCS64_GUEST_PAT_FULL                               0x2804
#define VMX_VMCS64_GUEST_PAT_HIGH                               0x2805
#define VMX_VMCS64_GUEST_EFER_FULL                              0x2806
#define VMX_VMCS64_GUEST_EFER_HIGH                              0x2807
#define VMX_VMCS64_GUEST_PERF_GLOBAL_CTRL_FULL                  0x2808
#define VMX_VMCS64_GUEST_PERF_GLOBAL_CTRL_HIGH                  0x2809
#define VMX_VMCS64_GUEST_PDPTE0_FULL                            0x280a
#define VMX_VMCS64_GUEST_PDPTE0_HIGH                            0x280b
#define VMX_VMCS64_GUEST_PDPTE1_FULL                            0x280c
#define VMX_VMCS64_GUEST_PDPTE1_HIGH                            0x280d
#define VMX_VMCS64_GUEST_PDPTE2_FULL                            0x280e
#define VMX_VMCS64_GUEST_PDPTE2_HIGH                            0x280f
#define VMX_VMCS64_GUEST_PDPTE3_FULL                            0x2810
#define VMX_VMCS64_GUEST_PDPTE3_HIGH                            0x2811
#define VMX_VMCS64_GUEST_BNDCFGS_FULL                           0x2812
#define VMX_VMCS64_GUEST_BNDCFGS_HIGH                           0x2813

/** 64-bit host-state fields.  */
#define VMX_VMCS64_HOST_PAT_FULL                                0x2c00
#define VMX_VMCS64_HOST_PAT_HIGH                                0x2c01
#define VMX_VMCS64_HOST_EFER_FULL                               0x2c02
#define VMX_VMCS64_HOST_EFER_HIGH                               0x2c03
#define VMX_VMCS64_HOST_PERF_GLOBAL_CTRL_FULL                   0x2c04
#define VMX_VMCS64_HOST_PERF_GLOBAL_CTRL_HIGH                   0x2c05

/** 32-bit control fields.  */
#define VMX_VMCS32_CTRL_PIN_EXEC                                0x4000
#define VMX_VMCS32_CTRL_PROC_EXEC                               0x4002
#define VMX_VMCS32_CTRL_EXCEPTION_BITMAP                        0x4004
#define VMX_VMCS32_CTRL_PAGEFAULT_ERROR_MASK                    0x4006
#define VMX_VMCS32_CTRL_PAGEFAULT_ERROR_MATCH                   0x4008
#define VMX_VMCS32_CTRL_CR3_TARGET_COUNT                        0x400a
#define VMX_VMCS32_CTRL_EXIT                                    0x400c
#define VMX_VMCS32_CTRL_EXIT_MSR_STORE_COUNT                    0x400e
#define VMX_VMCS32_CTRL_EXIT_MSR_LOAD_COUNT                     0x4010
#define VMX_VMCS32_CTRL_ENTRY                                   0x4012
#define VMX_VMCS32_CTRL_ENTRY_MSR_LOAD_COUNT                    0x4014
#define VMX_VMCS32_CTRL_ENTRY_INTERRUPTION_INFO                 0x4016
#define VMX_VMCS32_CTRL_ENTRY_EXCEPTION_ERRCODE                 0x4018
#define VMX_VMCS32_CTRL_ENTRY_INSTR_LENGTH                      0x401a
#define VMX_VMCS32_CTRL_TPR_THRESHOLD                           0x401c
#define VMX_VMCS32_CTRL_PROC_EXEC2                              0x401e
#define VMX_VMCS32_CTRL_PLE_GAP                                 0x4020
#define VMX_VMCS32_CTRL_PLE_WINDOW                              0x4022

/** 32-bits read-only fields. */
#define VMX_VMCS32_RO_VM_INSTR_ERROR                            0x4400
#define VMX_VMCS32_RO_EXIT_REASON                               0x4402
#define VMX_VMCS32_RO_EXIT_INTERRUPTION_INFO                    0x4404
#define VMX_VMCS32_RO_EXIT_INTERRUPTION_ERROR_CODE              0x4406
#define VMX_VMCS32_RO_IDT_VECTORING_INFO                        0x4408
#define VMX_VMCS32_RO_IDT_VECTORING_ERROR_CODE                  0x440a
#define VMX_VMCS32_RO_EXIT_INSTR_LENGTH                         0x440c
#define VMX_VMCS32_RO_EXIT_INSTR_INFO                           0x440e

/** 32-bit guest-state fields. */
#define VMX_VMCS32_GUEST_ES_LIMIT                               0x4800
#define VMX_VMCS32_GUEST_CS_LIMIT                               0x4802
#define VMX_VMCS32_GUEST_SS_LIMIT                               0x4804
#define VMX_VMCS32_GUEST_DS_LIMIT                               0x4806
#define VMX_VMCS32_GUEST_FS_LIMIT                               0x4808
#define VMX_VMCS32_GUEST_GS_LIMIT                               0x480a
#define VMX_VMCS32_GUEST_LDTR_LIMIT                             0x480c
#define VMX_VMCS32_GUEST_TR_LIMIT                               0x480e
#define VMX_VMCS32_GUEST_GDTR_LIMIT                             0x4810
#define VMX_VMCS32_GUEST_IDTR_LIMIT                             0x4812
#define VMX_VMCS32_GUEST_ES_ACCESS_RIGHTS                       0x4814
#define VMX_VMCS32_GUEST_CS_ACCESS_RIGHTS                       0x4816
#define VMX_VMCS32_GUEST_SS_ACCESS_RIGHTS                       0x4818
#define VMX_VMCS32_GUEST_DS_ACCESS_RIGHTS                       0x481a
#define VMX_VMCS32_GUEST_FS_ACCESS_RIGHTS                       0x481c
#define VMX_VMCS32_GUEST_GS_ACCESS_RIGHTS                       0x481e
#define VMX_VMCS32_GUEST_LDTR_ACCESS_RIGHTS                     0x4820
#define VMX_VMCS32_GUEST_TR_ACCESS_RIGHTS                       0x4822
#define VMX_VMCS32_GUEST_INT_STATE                              0x4824
#define VMX_VMCS32_GUEST_ACTIVITY_STATE                         0x4826
#define VMX_VMCS32_GUEST_SMBASE                                 0x4828
#define VMX_VMCS32_GUEST_SYSENTER_CS                            0x482a
#define VMX_VMCS32_PREEMPT_TIMER_VALUE                          0x482e

/** 32-bit host-state fields. */
#define VMX_VMCS32_HOST_SYSENTER_CS                             0x4C00

/** Natural-width control fields.  */
#define VMX_VMCS_CTRL_CR0_MASK                                  0x6000
#define VMX_VMCS_CTRL_CR4_MASK                                  0x6002
#define VMX_VMCS_CTRL_CR0_READ_SHADOW                           0x6004
#define VMX_VMCS_CTRL_CR4_READ_SHADOW                           0x6006
#define VMX_VMCS_CTRL_CR3_TARGET_VAL0                           0x6008
#define VMX_VMCS_CTRL_CR3_TARGET_VAL1                           0x600a
#define VMX_VMCS_CTRL_CR3_TARGET_VAL2                           0x600c
#define VMX_VMCS_CTRL_CR3_TARGET_VAL3                           0x600e

/** Natural-width read-only data fields. */
#define VMX_VMCS_RO_EXIT_QUALIFICATION                          0x6400
#define VMX_VMCS_RO_IO_RCX                                      0x6402
#define VMX_VMCS_RO_IO_RSI                                      0x6404
#define VMX_VMCS_RO_IO_RDI                                      0x6406
#define VMX_VMCS_RO_IO_RIP                                      0x6408
#define VMX_VMCS_RO_GUEST_LINEAR_ADDR                           0x640a

/** Natural-width guest-state fields. */
#define VMX_VMCS_GUEST_CR0                                      0x6800
#define VMX_VMCS_GUEST_CR3                                      0x6802
#define VMX_VMCS_GUEST_CR4                                      0x6804
#define VMX_VMCS_GUEST_ES_BASE                                  0x6806
#define VMX_VMCS_GUEST_CS_BASE                                  0x6808
#define VMX_VMCS_GUEST_SS_BASE                                  0x680a
#define VMX_VMCS_GUEST_DS_BASE                                  0x680c
#define VMX_VMCS_GUEST_FS_BASE                                  0x680e
#define VMX_VMCS_GUEST_GS_BASE                                  0x6810
#define VMX_VMCS_GUEST_LDTR_BASE                                0x6812
#define VMX_VMCS_GUEST_TR_BASE                                  0x6814
#define VMX_VMCS_GUEST_GDTR_BASE                                0x6816
#define VMX_VMCS_GUEST_IDTR_BASE                                0x6818
#define VMX_VMCS_GUEST_DR7                                      0x681a
#define VMX_VMCS_GUEST_RSP                                      0x681c
#define VMX_VMCS_GUEST_RIP                                      0x681e
#define VMX_VMCS_GUEST_RFLAGS                                   0x6820
#define VMX_VMCS_GUEST_PENDING_DEBUG_XCPTS                      0x6822
#define VMX_VMCS_GUEST_SYSENTER_ESP                             0x6824
#define VMX_VMCS_GUEST_SYSENTER_EIP                             0x6826

/** Natural-width host-state fields. */
#define VMX_VMCS_HOST_CR0                                       0x6c00
#define VMX_VMCS_HOST_CR3                                       0x6c02
#define VMX_VMCS_HOST_CR4                                       0x6c04
#define VMX_VMCS_HOST_FS_BASE                                   0x6c06
#define VMX_VMCS_HOST_GS_BASE                                   0x6c08
#define VMX_VMCS_HOST_TR_BASE                                   0x6c0a
#define VMX_VMCS_HOST_GDTR_BASE                                 0x6c0c
#define VMX_VMCS_HOST_IDTR_BASE                                 0x6c0e
#define VMX_VMCS_HOST_SYSENTER_ESP                              0x6c10
#define VMX_VMCS_HOST_SYSENTER_EIP                              0x6c12
#define VMX_VMCS_HOST_RSP                                       0x6c14
#define VMX_VMCS_HOST_RIP                                       0x6c16



/** @name VM-exit reason.
 * @{
 */
#define VMX_EXIT_REASON_BASIC(a)                                ((a) & 0xffff)
#define VMX_EXIT_REASON_HAS_ENTRY_FAILED(a)                     (((a) >> 31) & 1)
#define VMX_EXIT_REASON_ENTRY_FAILED                            RT_BIT(31)

/** Bit fields for VM-exit reason. */
/** The exit reason. */
#define VMX_BF_EXIT_REASON_BASIC_SHIFT                          0
#define VMX_BF_EXIT_REASON_BASIC_MASK                           (uint32)(0x0000ffff)
/** Bits 16:26 are reseved and MBZ. */
#define VMX_BF_EXIT_REASON_RSVD_16_26_SHIFT                     16
#define VMX_BF_EXIT_REASON_RSVD_16_26_MASK                      (uint32)(0x07ff0000)
/** Whether the VM-exit was incident to enclave mode. */
#define VMX_BF_EXIT_REASON_ENCLAVE_MODE_SHIFT                   27
#define VMX_BF_EXIT_REASON_ENCLAVE_MODE_MASK                    (uint32)(0x08000000)
/** Pending MTF (Monitor Trap Flag) during VM-exit (only applicable in SMM mode). */
#define VMX_BF_EXIT_REASON_SMM_PENDING_MTF_SHIFT                28
#define VMX_BF_EXIT_REASON_SMM_PENDING_MTF_MASK                 (uint32)(0x10000000)
/** VM-exit from VMX root operation (only possible with SMM). */
#define VMX_BF_EXIT_REASON_VMX_ROOT_MODE_SHIFT                  29
#define VMX_BF_EXIT_REASON_VMX_ROOT_MODE_MASK                   (uint32)(0x20000000)
/** Bit 30 is reserved and MBZ. */
#define VMX_BF_EXIT_REASON_RSVD_30_SHIFT                        30
#define VMX_BF_EXIT_REASON_RSVD_30_MASK                         (uint32)(0x40000000)
/** Whether VM-entry failed (currently only happens during loading guest-state
 *  or MSRs or machine check exceptions). */
#define VMX_BF_EXIT_REASON_ENTRY_FAILED_SHIFT                   31
#define VMX_BF_EXIT_REASON_ENTRY_FAILED_MASK                    (uint32)(0x80000000)
/** @} */

/** @name VMX Basic Exit Reasons.
 * @{
 */
/** -1 Invalid exit code */
#define VMX_EXIT_INVALID                                      (-1)
/** 0 Exception or non-maskable interrupt (NMI). */
#define VMX_EXIT_XCPT_OR_NMI                                    0
/** 1 External interrupt. */
#define VMX_EXIT_EXT_INT                                        1
/** 2 Triple fault. */
#define VMX_EXIT_TRIPLE_FAULT                                   2
/** 3 INIT signal. */
#define VMX_EXIT_INIT_SIGNAL                                    3
/** 4 Start-up IPI (SIPI). */
#define VMX_EXIT_SIPI                                           4
/** 5 I/O system-management interrupt (SMI). */
#define VMX_EXIT_IO_SMI                                         5
/** 6 Other SMI. */
#define VMX_EXIT_SMI                                            6
/** 7 Interrupt window exiting. */
#define VMX_EXIT_INT_WINDOW                                     7
/** 8 NMI window exiting. */
#define VMX_EXIT_NMI_WINDOW                                     8
/** 9 Task switch. */
#define VMX_EXIT_TASK_SWITCH                                    9
/** 10 Guest software attempted to execute CPUID. */
#define VMX_EXIT_CPUID                                          10
/** 11 Guest software attempted to execute GETSEC. */
#define VMX_EXIT_GETSEC                                         11
/** 12 Guest software attempted to execute HLT. */
#define VMX_EXIT_HLT                                            12
/** 13 Guest software attempted to execute INVD. */
#define VMX_EXIT_INVD                                           13
/** 14 Guest software attempted to execute INVLPG. */
#define VMX_EXIT_INVLPG                                         14
/** 15 Guest software attempted to execute RDPMC. */
#define VMX_EXIT_RDPMC                                          15
/** 16 Guest software attempted to execute RDTSC. */
#define VMX_EXIT_RDTSC                                          16
/** 17 Guest software attempted to execute RSM in SMM. */
#define VMX_EXIT_RSM                                            17
/** 18 Guest software executed VMCALL. */
#define VMX_EXIT_VMCALL                                         18
/** 19 Guest software executed VMCLEAR. */
#define VMX_EXIT_VMCLEAR                                        19
/** 20 Guest software executed VMLAUNCH. */
#define VMX_EXIT_VMLAUNCH                                       20
/** 21 Guest software executed VMPTRLD. */
#define VMX_EXIT_VMPTRLD                                        21
/** 22 Guest software executed VMPTRST. */
#define VMX_EXIT_VMPTRST                                        22
/** 23 Guest software executed VMREAD. */
#define VMX_EXIT_VMREAD                                         23
/** 24 Guest software executed VMRESUME. */
#define VMX_EXIT_VMRESUME                                       24
/** 25 Guest software executed VMWRITE. */
#define VMX_EXIT_VMWRITE                                        25
/** 26 Guest software executed VMXOFF. */
#define VMX_EXIT_VMXOFF                                         26
/** 27 Guest software executed VMXON. */
#define VMX_EXIT_VMXON                                          27
/** 28 Control-register accesses. */
#define VMX_EXIT_MOV_CRX                                        28
/** 29 Debug-register accesses. */
#define VMX_EXIT_MOV_DRX                                        29
/** 30 I/O instruction. */
#define VMX_EXIT_IO_INSTR                                       30
/** 31 RDMSR. Guest software attempted to execute RDMSR. */
#define VMX_EXIT_RDMSR                                          31
/** 32 WRMSR. Guest software attempted to execute WRMSR. */
#define VMX_EXIT_WRMSR                                          32
/** 33 VM-entry failure due to invalid guest state. */
#define VMX_EXIT_ERR_INVALID_GUEST_STATE                        33
/** 34 VM-entry failure due to MSR loading. */
#define VMX_EXIT_ERR_MSR_LOAD                                   34
/** 36 Guest software executed MWAIT. */
#define VMX_EXIT_MWAIT                                          36
/** 37 VM-exit due to monitor trap flag. */
#define VMX_EXIT_MTF                                            37
/** 39 Guest software attempted to execute MONITOR. */
#define VMX_EXIT_MONITOR                                        39
/** 40 Guest software attempted to execute PAUSE. */
#define VMX_EXIT_PAUSE                                          40
/** 41 VM-entry failure due to machine-check. */
#define VMX_EXIT_ERR_MACHINE_CHECK                              41
/** 43 TPR below threshold. Guest software executed MOV to CR8. */
#define VMX_EXIT_TPR_BELOW_THRESHOLD                            43
/** 44 APIC access. Guest software attempted to access memory at a physical
 *  address on the APIC-access page. */
#define VMX_EXIT_APIC_ACCESS                                    44
/** 45 Virtualized EOI. EOI virtualization was performed for a virtual
 *  interrupt whose vector indexed a bit set in the EOI-exit bitmap. */
#define VMX_EXIT_VIRTUALIZED_EOI                                45
/** 46 Access to GDTR or IDTR. Guest software attempted to execute LGDT, LIDT,
 *  SGDT, or SIDT. */
#define VMX_EXIT_GDTR_IDTR_ACCESS                               46
/** 47 Access to LDTR or TR. Guest software attempted to execute LLDT, LTR,
 *  SLDT, or STR. */
#define VMX_EXIT_LDTR_TR_ACCESS                                 47
/** 48 EPT violation. An attempt to access memory with a guest-physical address
 *  was disallowed by the configuration of the EPT paging structures. */
#define VMX_EXIT_EPT_VIOLATION                                  48
/** 49 EPT misconfiguration. An attempt to access memory with a guest-physical
 *  address encountered a misconfigured EPT paging-structure entry. */
#define VMX_EXIT_EPT_MISCONFIG                                  49
/** 50 INVEPT. Guest software attempted to execute INVEPT. */
#define VMX_EXIT_INVEPT                                         50
/** 51 RDTSCP. Guest software attempted to execute RDTSCP. */
#define VMX_EXIT_RDTSCP                                         51
/** 52 VMX-preemption timer expired. The preemption timer counted down to zero. */
#define VMX_EXIT_PREEMPT_TIMER                                  52
/** 53 INVVPID. Guest software attempted to execute INVVPID. */
#define VMX_EXIT_INVVPID                                        53
/** 54 WBINVD. Guest software attempted to execute WBINVD. */
#define VMX_EXIT_WBINVD                                         54
/** 55 XSETBV. Guest software attempted to execute XSETBV. */
#define VMX_EXIT_XSETBV                                         55
/** 56 APIC write. Guest completed write to virtual-APIC. */
#define VMX_EXIT_APIC_WRITE                                     56
/** 57 RDRAND. Guest software attempted to execute RDRAND. */
#define VMX_EXIT_RDRAND                                         57
/** 58 INVPCID. Guest software attempted to execute INVPCID. */
#define VMX_EXIT_INVPCID                                        58
/** 59 VMFUNC. Guest software attempted to execute VMFUNC. */
#define VMX_EXIT_VMFUNC                                         59
/** 60 ENCLS. Guest software attempted to execute ENCLS. */
#define VMX_EXIT_ENCLS                                          60
/** 61 - RDSEED - Guest software attempted to executed RDSEED and exiting was
 * enabled. */
#define VMX_EXIT_RDSEED                                         61
/** 62 - Page-modification log full. */
#define VMX_EXIT_PML_FULL                                       62
/** 63 - XSAVES. Guest software attempted to execute XSAVES and exiting was
 * enabled (XSAVES/XRSTORS was enabled too, of course). */
#define VMX_EXIT_XSAVES                                         63
/** 64 - XRSTORS. Guest software attempted to execute XRSTORS and exiting
 * was enabled (XSAVES/XRSTORS was enabled too, of course). */
#define VMX_EXIT_XRSTORS                                        64
/** 66 - SPP-related event. Attempt to determine an access' sub-page write
 *  permission encountered an SPP miss or misconfiguration. */
#define VMX_EXIT_SPP_EVENT                                      66
/* 67 - UMWAIT. Guest software attempted to execute UMWAIT and exiting was enabled. */
#define VMX_EXIT_UMWAIT                                         67
/** 68 - TPAUSE. Guest software attempted to execute TPAUSE and exiting was
 *  enabled. */
#define VMX_EXIT_TPAUSE                                         68
/** The maximum exit value (inclusive). */
#define VMX_EXIT_MAX                                            (VMX_EXIT_TPAUSE)
/** @} */


/** @name VM-entry controls.
 * @{
 */
/** Load guest debug controls (dr7 & IA32_DEBUGCTL_MSR) (forced to 1 on the
 *  'first' VT-x capable CPUs; this actually includes the newest Nehalem CPUs) */
#define VMX_ENTRY_CTLS_LOAD_DEBUG                               (uint32)(1 << 2)
/** 64-bit guest mode. Must be 0 for CPUs that don't support AMD64. */
#define VMX_ENTRY_CTLS_IA32E_MODE_GUEST                         (uint32)(1 << 9)
/** In SMM mode after VM-entry. */
#define VMX_ENTRY_CTLS_ENTRY_TO_SMM                             (uint32)(1 << 10)
/** Disable dual treatment of SMI and SMM; must be zero for VM-entry outside of SMM. */
#define VMX_ENTRY_CTLS_DEACTIVATE_DUAL_MON                      (uint32)(1 << 11)
/** Whether the guest IA32_PERF_GLOBAL_CTRL MSR is loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_PERF_MSR                            (uint32)(1 << 13)
/** Whether the guest IA32_PAT MSR is loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_PAT_MSR                             (uint32)(1 << 14)
/** Whether the guest IA32_EFER MSR is loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_EFER_MSR                            (uint32)(1 << 15)
/** Whether the guest IA32_BNDCFGS MSR is loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_BNDCFGS_MSR                         (uint32)(1 << 16)
/** Whether to conceal VMX from Intel PT (Processor Trace). */
#define VMX_ENTRY_CTLS_CONCEAL_VMX_FROM_PT                      (uint32)(1 << 17)
/** Whether the guest IA32_RTIT MSR is loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_RTIT_CTL_MSR                        (uint32)(1 << 18)
/** Whether the guest CET-related MSRs and SPP are loaded on VM-entry. */
#define VMX_ENTRY_CTLS_LOAD_CET_STATE                           (uint32)(1 << 20)
/** Default1 class when true-capability MSRs are not supported. */
#define VMX_ENTRY_CTLS_DEFAULT1                                 (uint32)(0x000011ff)

/** Bit fields for MSR_IA32_VMX_ENTRY_CTLS and VM-entry controls field in the
 *  VMCS. */
#define VMX_BF_ENTRY_CTLS_UNDEF_0_1_SHIFT                       0
#define VMX_BF_ENTRY_CTLS_UNDEF_0_1_MASK                        (uint32)(0x00000003)
#define VMX_BF_ENTRY_CTLS_LOAD_DEBUG_SHIFT                      2
#define VMX_BF_ENTRY_CTLS_LOAD_DEBUG_MASK                       (uint32)(0x00000004)
#define VMX_BF_ENTRY_CTLS_UNDEF_3_8_SHIFT                       3
#define VMX_BF_ENTRY_CTLS_UNDEF_3_8_MASK                        (uint32)(0x000001f8)
#define VMX_BF_ENTRY_CTLS_IA32E_MODE_GUEST_SHIFT                9
#define VMX_BF_ENTRY_CTLS_IA32E_MODE_GUEST_MASK                 (uint32)(0x00000200)
#define VMX_BF_ENTRY_CTLS_ENTRY_SMM_SHIFT                       10
#define VMX_BF_ENTRY_CTLS_ENTRY_SMM_MASK                        (uint32)(0x00000400)
#define VMX_BF_ENTRY_CTLS_DEACTIVATE_DUAL_MON_SHIFT             11
#define VMX_BF_ENTRY_CTLS_DEACTIVATE_DUAL_MON_MASK              (uint32)(0x00000800)
#define VMX_BF_ENTRY_CTLS_UNDEF_12_SHIFT                        12
#define VMX_BF_ENTRY_CTLS_UNDEF_12_MASK                         (uint32)(0x00001000)
#define VMX_BF_ENTRY_CTLS_LOAD_PERF_MSR_SHIFT                   13
#define VMX_BF_ENTRY_CTLS_LOAD_PERF_MSR_MASK                    (uint32)(0x00002000)
#define VMX_BF_ENTRY_CTLS_LOAD_PAT_MSR_SHIFT                    14
#define VMX_BF_ENTRY_CTLS_LOAD_PAT_MSR_MASK                     (uint32)(0x00004000)
#define VMX_BF_ENTRY_CTLS_LOAD_EFER_MSR_SHIFT                   15
#define VMX_BF_ENTRY_CTLS_LOAD_EFER_MSR_MASK                    (uint32)(0x00008000)
#define VMX_BF_ENTRY_CTLS_LOAD_BNDCFGS_MSR_SHIFT                16
#define VMX_BF_ENTRY_CTLS_LOAD_BNDCFGS_MSR_MASK                 (uint32)(0x00010000)
#define VMX_BF_ENTRY_CTLS_CONCEAL_VMX_FROM_PT_SHIFT             17
#define VMX_BF_ENTRY_CTLS_CONCEAL_VMX_FROM_PT_MASK              (uint32)(0x00020000)
#define VMX_BF_ENTRY_CTLS_LOAD_RTIT_CTL_MSR_SHIFT               18
#define VMX_BF_ENTRY_CTLS_LOAD_RTIT_CTL_MSR_MASK                (uint32)(0x00040000)
#define VMX_BF_ENTRY_CTLS_UNDEF_19_31_SHIFT                     19
#define VMX_BF_ENTRY_CTLS_UNDEF_19_31_MASK                      (uint32)(0xfff80000)

/** @} */


/** @name VM-exit controls.
 * @{
 */
/** Save guest debug controls (dr7 & IA32_DEBUGCTL_MSR) (forced to 1 on the
 *  'first' VT-x capable CPUs; this actually includes the newest Nehalem CPUs) */
#define VMX_EXIT_CTLS_SAVE_DEBUG                                (uint32)(1 << 2)
/** Return to long mode after a VM-exit. */
#define VMX_EXIT_CTLS_HOST_ADDR_SPACE_SIZE                      (vuint32)(1 << 9)
/** Whether the host IA32_PERF_GLOBAL_CTRL MSR is loaded on VM-exit. */
#define VMX_EXIT_CTLS_LOAD_PERF_MSR                             (uint32)(1 << 12)
/** Acknowledge external interrupts with the irq controller if one caused a VM-exit. */
#define VMX_EXIT_CTLS_ACK_EXT_INT                               (uint32)(1 << 15)
/** Whether the guest IA32_PAT MSR is saved on VM-exit. */
#define VMX_EXIT_CTLS_SAVE_PAT_MSR                              (uint32)(1 << 18)
/** Whether the host IA32_PAT MSR is loaded on VM-exit. */
#define VMX_EXIT_CTLS_LOAD_PAT_MSR                              (uint32)(1 << 19)
/** Whether the guest IA32_EFER MSR is saved on VM-exit. */
#define VMX_EXIT_CTLS_SAVE_EFER_MSR                             (uint32)(1 << 20)
/** Whether the host IA32_EFER MSR is loaded on VM-exit. */
#define VMX_EXIT_CTLS_LOAD_EFER_MSR                             (uint32)(1 << 21)
/** Whether the value of the VMX preemption timer is saved on every VM-exit. */
#define VMX_EXIT_CTLS_SAVE_PREEMPT_TIMER                        (uint32)(1 << 22)
/** Whether IA32_BNDCFGS MSR is cleared on VM-exit. */
#define VMX_EXIT_CTLS_CLEAR_BNDCFGS_MSR                         (uint32)(1 << 23)
/** Whether to conceal VMX from Intel PT. */
#define VMX_EXIT_CTLS_CONCEAL_VMX_FROM_PT                       (uint32)(1 << 24)
/** Whether IA32_RTIT_CTL MSR is cleared on VM-exit. */
#define VMX_EXIT_CTLS_CLEAR_RTIT_CTL_MSR                        (uint32)(1 << 25)
/** Whether CET-related MSRs and SPP are loaded on VM-exit. */
#define VMX_EXIT_CTLS_LOAD_CET_STATE                            (uint32)(1 << 28)
/** Default1 class when true-capability MSRs are not supported. */
#define VMX_EXIT_CTLS_DEFAULT1                                  (uint32)(0x00036dff)

// clang-format on

// See: 30.4 VM INSTRUCTION ERROR NUMBERS
#define VMX_INSTRUCTION_ERROR_NUMBERS(XX)                                                                                                      \
  XX (0, "")                                                                                                                                   \
  XX (1, "VMCALL executed in VMX root operation")                                                                                              \
  XX (2, "VMCLEAR with invalid physical address")                                                                                              \
  XX (3, "VMCLEAR with VMXON pointer")                                                                                                         \
  XX (4, "VMLAUNCH with non-clear VMCS")                                                                                                       \
  XX (5, "VMRESUME with non-launched VMCS")                                                                                                    \
  XX (6, "VMRESUME after VMXOFF (VMXOFF and VMXON between VMLAUNCH and VMRESUME)")                                                             \
  XX (7, "VM entry with invalid control field(s)")                                                                                             \
  XX (8, "VM entry with invalid host-state field(s)")                                                                                          \
  XX (9, "VMPTRLD with invalid physical address")                                                                                              \
  XX (10, "VMPTRLD with VMXON pointer")                                                                                                        \
  XX (11, "VMPTRLD with incorrect VMCS revision identifier")                                                                                   \
  XX (12, "VMREAD/VMWRITE from/to unsupported VMCS component")                                                                                 \
  XX (13, "VMWRITE to read-only VMCS component")                                                                                               \
  XX (15, "VMXON executed in VMX root operation")                                                                                              \
  XX (16, "VM entry with invalid executive-VMCS pointer2")                                                                                     \
  XX (17, "VM entry with non-launched executive VMCS2")                                                                                        \
  XX (18, "VM entry with executive-VMCS pointer not VMXON pointer (when attempting to deactivate the dual-monitor treatment of SMIs and SMM)") \
  XX (19, "VMCALL with non-clear VMCS (when attempting to activate the dual-monitor treatment of SMIs and SMM)")                               \
  XX (20, "VMCALL with invalid VM-exit control fields")                                                                                        \
  XX (22, "VMCALL with incorrect MSEG revision identifier (when attempting to activate the dual-monitor treatment of SMIs and SMM)")           \
  XX (23, "VMXOFF under dual-monitor treatment of SMIs and SMM")                                                                               \
  XX (24, "VMCALL with invalid SMM-monitor features (when attempting to activate the dual-monitor treatment of SMIs and SMM)")                 \
  XX (25, "VM entry with invalid VM-execution control fields in executive VMCS (when attempting to return from SMM)")                          \
  XX (26, "VM entry with events blocked by MOV SS.")                                                                                           \
  XX (28, "Invalid operand to INVEPT/INVVPID.")

const char* VMX_INSTRUCTION_ERROR_STRING (int num);

// clang-format on

/// See: Definitions of Primary Processor-Based VM-Execution Controls
typedef union {
  struct
  {
    vuint8 reserved1 : 2;                  //!< [0:1]
    vuint8 interrupt_window_exiting : 1;   //!< [2]
    vuint8 use_tsc_offseting : 1;          //!< [3]
    vuint8 reserved2 : 3;                  //!< [4:6]
    vuint8 hlt_exiting : 1;                //!< [7]
    vuint8 reserved3 : 1;                  //!< [8]
    vuint8 invlpg_exiting : 1;             //!< [9]
    vuint8 mwait_exiting : 1;              //!< [10]
    vuint8 rdpmc_exiting : 1;              //!< [11]
    vuint8 rdtsc_exiting : 1;              //!< [12]
    vuint8 reserved4 : 2;                  //!< [13:14]
    vuint8 cr3_load_exiting : 1;           //!< [15]
    vuint8 cr3_store_exiting : 1;          //!< [16]
    vuint8 reserved5 : 2;                  //!< [17:18]
    vuint8 cr8_load_exiting : 1;           //!< [19]
    vuint8 cr8_store_exiting : 1;          //!< [20]
    vuint8 use_tpr_shadow : 1;             //!< [21]
    vuint8 nmi_window_exiting : 1;         //!< [22]
    vuint8 mov_dr_exiting : 1;             //!< [23]
    vuint8 unconditional_io_exiting : 1;   //!< [24]
    vuint8 use_io_bitmaps : 1;             //!< [25]
    vuint8 reserved6 : 1;                  //!< [26]
    vuint8 monitor_trap_flag : 1;          //!< [27]
    vuint8 use_msr_bitmaps : 1;            //!< [28]
    vuint8 monitor_exiting : 1;            //!< [29]
    vuint8 pause_exiting : 1;              //!< [30]
    vuint8 activate_secondary_control : 1; //!< [31]
  };
  vuint32 bits;
} VmxPrimaryProcessorBasedControls;
static_assert (sizeof (VmxPrimaryProcessorBasedControls) == 4, "");

/// See: Definitions of Secondary Processor-Based VM-Execution Controls
typedef union {
  struct
  {
    vuint8 virtualize_apic_accesses : 1;           //!< [0]
    vuint8 enable_ept : 1;                         //!< [1]
    vuint8 descriptor_table_exiting : 1;           //!< [2]
    vuint8 enable_rdtscp : 1;                      //!< [3]
    vuint8 virtualize_x2apic_mode : 1;             //!< [4]
    vuint8 enable_vpid : 1;                        //!< [5]
    vuint8 wbinvd_exiting : 1;                     //!< [6]
    vuint8 unrestricted_guest : 1;                 //!< [7]
    vuint8 apic_register_virtualization : 1;       //!< [8]
    vuint8 virtual_interrupt_delivery : 1;         //!< [9]
    vuint8 pause_loop_exiting : 1;                 //!< [10]
    vuint8 rdrand_exiting : 1;                     //!< [11]
    vuint8 enable_invpcid : 1;                     //!< [12]
    vuint8 enable_vm_functions : 1;                //!< [13]
    vuint8 vmcs_shadowing : 1;                     //!< [14]
    vuint8 reserved1 : 1;                          //!< [15]
    vuint8 rdseed_exiting : 1;                     //!< [16]
    vuint8 reserved2 : 1;                          //!< [17]
    vuint8 enable_ept_violation_ve : 1;            //!< [18]
    vuint8 reserved3 : 1;                          //!< [19]
    vuint8 enable_xsaves_xstors : 1;               //!< [20]
    vuint8 reserved4 : 1;                          //!< [21]
    vuint8 mode_based_execute_control_for_ept : 1; //!< [22]
    vuint8 reserved5 : 2;                          //!< [23:24]
    vuint8 use_tsc_scaling : 1;                    //!< [25]
  };
  vuint32 bits;
} VmxSecondaryProcessorBasedControls;
static_assert (sizeof (VmxSecondaryProcessorBasedControls) == 4, "");

typedef struct
{
  vuint64 rax;
  vuint64 rbx;
  vuint64 rcx;
  vuint64 rdx;
  vuint64 rsi;
  vuint64 rdi;
  vuint64 rip;
  vuint64 r8;
  vuint64 r9;
  vuint64 r10;
  vuint64 r11;
  vuint64 r12;
  vuint64 r13;
  vuint64 r14;
  vuint64 r15;
  vuint64 flags;
} VmxVMExitContext;

#endif //vVMX_H

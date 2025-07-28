/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/22/2025 09:47:14 UTC. Any changes will be lost.
* 
* Model ID  d29699dd-ff7f-4a1f-bab8-fcf8151ddb90
* 
* Memory    Size                      Efficiency
* Buffers   5120 bytes (RAM)          80 %
* State     512 bytes (RAM)           100 %
* Readonly  243352 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-medium-balanced-3
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | Falling
* 2           | Squatting
* 3           | normal
* 4           | static
* 5           | Sitting
* 
* Layer                          Shape           Type       Function
* Input Layer                    [60,15]         float      compute
*    shape = [60,15]
* Convolution 1D                 [30,16]         float      compute
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,15,16]
* Batch Normalization            [30,16]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [30,16]         float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [15,32]         float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,32]
* Convolution 1D                 [8,32]          float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,32,32]
* Batch Normalization            [8,32]          float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [8,32]          float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [8,64]          float      compute
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,64]
* Convolution 1D                 [8,64]          float      compute
*    filters = 64
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,64,64]
* Batch Normalization            [8,64]          float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[64]
*    beta = float[64]
*    mean = float[64]
*    variance = float[64]
* Activation                     [8,64]          float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [4,64]          float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [4,64]          float      compute
*    rate = 0.1
*    trainable = True
* Long Short-Term Memory         [4,64]          float      compute
*    units = 64
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[64,256]
*    recurrent_kernel = float[64,256]
*    bias = float[256]
* Global average pooling 1D      [64]            float      compute
*    trainable = True
* Dense                          [6]             float      compute
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[64,6]
*    bias = float[6]
* Activation                     [6]             float      compute
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* void IMAI_compute(const float *restrict data_in, float *restrict data_out)
*    Description: Compute a forward pass
*    Parameter data_in is Input of size float[60,15].
*    Parameter data_out is Output of size float[6].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 91.497 %
* (F1S) F1 Score 91.526 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              136              147               17              147               91
* (FN) False Negative or Incorrect Negative Prediction                0                9               12                0               21                8
* (FP) False Positive or Incorrect Positive Prediction                0               13                9                6               10               12
* (TN) True Negative or Correct Negative Prediction                 588              430              420              565              410              477
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          93.79 %          92.45 %         100.00 %          87.50 %          91.92 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          97.07 %          97.90 %          98.95 %          97.62 %          97.55 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          91.28 %          94.23 %          73.91 %          93.63 %          88.35 %
* (NPV) Negative Predictive Value                              100.00 %          97.95 %          97.22 %         100.00 %          95.13 %          98.35 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           6.21 %           7.55 %           0.00 %          12.50 %           8.08 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           2.93 %           2.10 %           1.05 %           2.38 %           2.45 %
* (FDR) False Discovery Rate                                   100.00 %           8.72 %           5.77 %          26.09 %           6.37 %          11.65 %
* (FOR) False Omission Rate                                      0.00 %           2.05 %           2.78 %           0.00 %           4.87 %           1.65 %
* (F1S) F1 Score                                               100.00 %          92.52 %          93.33 %          85.00 %          90.46 %          90.10 %
*/


#define IMAI_TEST_AVG_ACC 0.9149659863945578 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9152603134035892 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 588, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 136, FN: 9, FP: 13, TN: 430, TPR: 0.9379310344827, TNR: 0.9706546275395, PPV: 0.9127516778523, NPV: 0.9794988610478, FNR: 0.0620689655172, FPR: 0.0293453724604, FDR: 0.0872483221476, FOR: 0.0205011389521, F1S: 0.9251700680272, }, \
 {name: "Squatting", TP: 147, FN: 21, FP: 10, TN: 410, TPR: 0.875, TNR: 0.9761904761904, PPV: 0.9363057324840, NPV: 0.9512761020881, FNR: 0.125, FPR: 0.0238095238095, FDR: 0.0636942675159, FOR: 0.0487238979118, F1S: 0.9046153846153, }, \
 {name: "normal", TP: 147, FN: 12, FP: 9, TN: 420, TPR: 0.9245283018867, TNR: 0.9790209790209, PPV: 0.9423076923076, NPV: 0.9722222222222, FNR: 0.0754716981132, FPR: 0.0209790209790, FDR: 0.0576923076923, FOR: 0.0277777777777, F1S: 0.9333333333333, }, \
 {name: "static", TP: 91, FN: 8, FP: 12, TN: 477, TPR: 0.9191919191919, TNR: 0.9754601226993, PPV: 0.8834951456310, NPV: 0.9835051546391, FNR: 0.0808080808080, FPR: 0.0245398773006, FDR: 0.1165048543689, FOR: 0.0164948453608, F1S: 0.9009900990099, }, \
 {name: "Sitting", TP: 17, FN: 0, FP: 6, TN: 565, TPR: 1, TNR: 0.9894921190893, PPV: 0.7391304347826, NPV: 1, FNR: 0, FPR: 0.0105078809106, FDR: 0.2608695652173, FOR: 0, F1S: 0.85, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 93.939 %
* (F1S) F1 Score 93.960 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              654              665               71              707              414
* (FN) False Negative or Incorrect Negative Prediction                0                6               56                7               57               36
* (FP) False Positive or Incorrect Positive Prediction                0               35               25               24               45               33
* (TN) True Negative or Correct Negative Prediction                2673             1978             1927             2571             1864             2190
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          99.09 %          92.23 %          91.03 %          92.54 %          92.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.26 %          98.72 %          99.08 %          97.64 %          98.52 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          94.92 %          96.38 %          74.74 %          94.02 %          92.62 %
* (NPV) Negative Predictive Value                              100.00 %          99.70 %          97.18 %          99.73 %          97.03 %          98.38 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           0.91 %           7.77 %           8.97 %           7.46 %           8.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.74 %           1.28 %           0.92 %           2.36 %           1.48 %
* (FDR) False Discovery Rate                                   100.00 %           5.08 %           3.62 %          25.26 %           5.98 %           7.38 %
* (FOR) False Omission Rate                                      0.00 %           0.30 %           2.82 %           0.27 %           2.97 %           1.62 %
* (F1S) F1 Score                                               100.00 %          96.96 %          94.26 %          82.08 %          93.27 %          92.31 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9393939393939394 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9396015507598009 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2673, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 654, FN: 6, FP: 35, TN: 1978, TPR: 0.9909090909090, TNR: 0.9826130153999, PPV: 0.9492017416545, NPV: 0.9969758064516, FNR: 0.0090909090909, FPR: 0.0173869846000, FDR: 0.0507982583454, FOR: 0.0030241935483, F1S: 0.9696071163825, }, \
 {name: "Squatting", TP: 707, FN: 57, FP: 45, TN: 1864, TPR: 0.9253926701570, TNR: 0.9764274489261, PPV: 0.9401595744680, NPV: 0.9703279541905, FNR: 0.0746073298429, FPR: 0.0235725510738, FDR: 0.0598404255319, FOR: 0.0296720458094, F1S: 0.9327176781002, }, \
 {name: "normal", TP: 665, FN: 56, FP: 25, TN: 1927, TPR: 0.9223300970873, TNR: 0.9871926229508, PPV: 0.9637681159420, NPV: 0.9717599596570, FNR: 0.0776699029126, FPR: 0.0128073770491, FDR: 0.0362318840579, FOR: 0.0282400403429, F1S: 0.9425939050318, }, \
 {name: "static", TP: 414, FN: 36, FP: 33, TN: 2190, TPR: 0.92, TNR: 0.9851551956815, PPV: 0.9261744966442, NPV: 0.9838274932614, FNR: 0.08, FPR: 0.0148448043184, FDR: 0.0738255033557, FOR: 0.0161725067385, F1S: 0.9230769230769, }, \
 {name: "Sitting", TP: 71, FN: 7, FP: 24, TN: 2571, TPR: 0.9102564102564, TNR: 0.9907514450867, PPV: 0.7473684210526, NPV: 0.9972847168347, FNR: 0.0897435897435, FPR: 0.0092485549132, FDR: 0.2526315789473, FOR: 0.0027152831652, F1S: 0.8208092485549, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 88.183 %
* (F1S) F1 Score 88.149 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              136              130               11              141               82
* (FN) False Negative or Incorrect Negative Prediction                0                4               23                6               21               13
* (FP) False Positive or Incorrect Positive Prediction                0               14               14                7               20               12
* (TN) True Negative or Correct Negative Prediction                 567              413              400              543              385              460
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.14 %          84.97 %          64.71 %          87.04 %          86.32 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          96.72 %          96.62 %          98.73 %          95.06 %          97.46 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          90.67 %          90.28 %          61.11 %          87.58 %          87.23 %
* (NPV) Negative Predictive Value                              100.00 %          99.04 %          94.56 %          98.91 %          94.83 %          97.25 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.86 %          15.03 %          35.29 %          12.96 %          13.68 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           3.28 %           3.38 %           1.27 %           4.94 %           2.54 %
* (FDR) False Discovery Rate                                   100.00 %           9.33 %           9.72 %          38.89 %          12.42 %          12.77 %
* (FOR) False Omission Rate                                      0.00 %           0.96 %           5.44 %           1.09 %           5.17 %           2.75 %
* (F1S) F1 Score                                               100.00 %          93.79 %          87.54 %          62.86 %          87.31 %          86.77 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8818342151675485 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8814917954044036 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 567, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 136, FN: 4, FP: 14, TN: 413, TPR: 0.9714285714285, TNR: 0.9672131147540, PPV: 0.9066666666666, NPV: 0.9904076738609, FNR: 0.0285714285714, FPR: 0.0327868852459, FDR: 0.0933333333333, FOR: 0.0095923261390, F1S: 0.9379310344827, }, \
 {name: "Squatting", TP: 141, FN: 21, FP: 20, TN: 385, TPR: 0.8703703703703, TNR: 0.9506172839506, PPV: 0.8757763975155, NPV: 0.9482758620689, FNR: 0.1296296296296, FPR: 0.0493827160493, FDR: 0.1242236024844, FOR: 0.0517241379310, F1S: 0.8730650154798, }, \
 {name: "normal", TP: 130, FN: 23, FP: 14, TN: 400, TPR: 0.8496732026143, TNR: 0.9661835748792, PPV: 0.9027777777777, NPV: 0.9456264775413, FNR: 0.1503267973856, FPR: 0.0338164251207, FDR: 0.0972222222222, FOR: 0.0543735224586, F1S: 0.8754208754208, }, \
 {name: "static", TP: 82, FN: 13, FP: 12, TN: 460, TPR: 0.8631578947368, TNR: 0.9745762711864, PPV: 0.8723404255319, NPV: 0.9725158562367, FNR: 0.1368421052631, FPR: 0.0254237288135, FDR: 0.1276595744680, FOR: 0.0274841437632, F1S: 0.8677248677248, }, \
 {name: "Sitting", TP: 11, FN: 6, FP: 7, TN: 543, TPR: 0.6470588235294, TNR: 0.9872727272727, PPV: 0.6111111111111, NPV: 0.9890710382513, FNR: 0.3529411764705, FPR: 0.0127272727272, FDR: 0.3888888888888, FOR: 0.0109289617486, F1S: 0.6285714285714, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xdd, 0x99, 0x96, 0xd2, 0x7f, 0xff, 0x1f, 0x4a, 0xba, 0xb8, 0xfc, 0xf8, 0x15, 0x1d, 0xdb, 0x90}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [60,15] (3600 bytes)
#define IMAI_DATA_IN_COUNT (900)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [6] (24 bytes)
#define IMAI_DATA_OUT_COUNT (6)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (80)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */

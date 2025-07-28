/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/24/2025 07:40:31 UTC. Any changes will be lost.
* 
* Model ID  9c0dcffc-d9f6-4457-a87f-b8e17c9097e3
* 
* Memory    Size                      Efficiency
* Buffers   7680 bytes (RAM)          100 %
* State     256 bytes (RAM)           100 %
* Readonly  84888 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-small-balanced-3
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
* Convolution 1D                 [30,32]         float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,15,32]
* Batch Normalization            [30,32]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [30,32]         float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [30,32]         float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,32,32]
* Convolution 1D                 [30,32]         float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,32,32]
* Batch Normalization            [30,32]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [30,32]         float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [15,32]         float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [15,32]         float      compute
*    rate = 0.1
*    trainable = True
* Long Short-Term Memory         [15,32]         float      compute
*    units = 32
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,128]
*    recurrent_kernel = float[32,128]
*    bias = float[128]
* Global average pooling 1D      [32]            float      compute
*    trainable = True
* Dense                          [6]             float      compute
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,6]
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
* (ACC) Accuracy 94.118 %
* (F1S) F1 Score 94.124 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              136              150               16              151               91
* (FN) False Negative or Incorrect Negative Prediction                0                7                6                1               14                6
* (FP) False Positive or Incorrect Positive Prediction                0                5               10                3               12                4
* (TN) True Negative or Correct Negative Prediction                 578              430              412              558              401              477
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          95.10 %          96.15 %          94.12 %          91.52 %          93.81 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.85 %          97.63 %          99.47 %          97.09 %          99.17 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          96.45 %          93.75 %          84.21 %          92.64 %          95.79 %
* (NPV) Negative Predictive Value                              100.00 %          98.40 %          98.56 %          99.82 %          96.63 %          98.76 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           4.90 %           3.85 %           5.88 %           8.48 %           6.19 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.15 %           2.37 %           0.53 %           2.91 %           0.83 %
* (FDR) False Discovery Rate                                   100.00 %           3.55 %           6.25 %          15.79 %           7.36 %           4.21 %
* (FOR) False Omission Rate                                      0.00 %           1.60 %           1.44 %           0.18 %           3.37 %           1.24 %
* (F1S) F1 Score                                               100.00 %          95.77 %          94.94 %          88.89 %          92.07 %          94.79 %
*/


#define IMAI_TEST_AVG_ACC 0.9411764705882353 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9412435498040707 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 578, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 136, FN: 7, FP: 5, TN: 430, TPR: 0.9510489510489, TNR: 0.9885057471264, PPV: 0.9645390070921, NPV: 0.9839816933638, FNR: 0.0489510489510, FPR: 0.0114942528735, FDR: 0.0354609929078, FOR: 0.0160183066361, F1S: 0.9577464788732, }, \
 {name: "Squatting", TP: 151, FN: 14, FP: 12, TN: 401, TPR: 0.9151515151515, TNR: 0.9709443099273, PPV: 0.9263803680981, NPV: 0.9662650602409, FNR: 0.0848484848484, FPR: 0.0290556900726, FDR: 0.0736196319018, FOR: 0.0337349397590, F1S: 0.9207317073170, }, \
 {name: "normal", TP: 150, FN: 6, FP: 10, TN: 412, TPR: 0.9615384615384, TNR: 0.9763033175355, PPV: 0.9375, NPV: 0.9856459330143, FNR: 0.0384615384615, FPR: 0.0236966824644, FDR: 0.0625, FOR: 0.0143540669856, F1S: 0.9493670886075, }, \
 {name: "static", TP: 91, FN: 6, FP: 4, TN: 477, TPR: 0.9381443298969, TNR: 0.9916839916839, PPV: 0.9578947368421, NPV: 0.9875776397515, FNR: 0.0618556701030, FPR: 0.0083160083160, FDR: 0.0421052631578, FOR: 0.0124223602484, F1S: 0.9479166666666, }, \
 {name: "Sitting", TP: 16, FN: 1, FP: 3, TN: 558, TPR: 0.9411764705882, TNR: 0.9946524064171, PPV: 0.8421052631578, NPV: 0.9982110912343, FNR: 0.0588235294117, FPR: 0.0053475935828, FDR: 0.1578947368421, FOR: 0.0017889087656, F1S: 0.8888888888888, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 97.659 %
* (F1S) F1 Score 97.678 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              650              709               76              748              445
* (FN) False Negative or Incorrect Negative Prediction                0               14               17                3               21                8
* (FP) False Positive or Incorrect Positive Prediction                0                1               10               13               17               22
* (TN) True Negative or Correct Negative Prediction                2691             2026             1955             2599             1905             2216
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.89 %          97.66 %          96.20 %          97.27 %          98.23 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.95 %          99.49 %          99.50 %          99.12 %          99.02 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.85 %          98.61 %          85.39 %          97.78 %          95.29 %
* (NPV) Negative Predictive Value                              100.00 %          99.31 %          99.14 %          99.88 %          98.91 %          99.64 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.11 %           2.34 %           3.80 %           2.73 %           1.77 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.05 %           0.51 %           0.50 %           0.88 %           0.98 %
* (FDR) False Discovery Rate                                   100.00 %           0.15 %           1.39 %          14.61 %           2.22 %           4.71 %
* (FOR) False Omission Rate                                      0.00 %           0.69 %           0.86 %           0.12 %           1.09 %           0.36 %
* (F1S) F1 Score                                               100.00 %          98.86 %          98.13 %          90.48 %          97.52 %          96.74 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9765886287625418 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9767801431655615 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2691, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 650, FN: 14, FP: 1, TN: 2026, TPR: 0.9789156626506, TNR: 0.9995066600888, PPV: 0.9984639016897, NPV: 0.9931372549019, FNR: 0.0210843373493, FPR: 0.0004933399111, FDR: 0.0015360983102, FOR: 0.0068627450980, F1S: 0.9885931558935, }, \
 {name: "Squatting", TP: 748, FN: 21, FP: 17, TN: 1905, TPR: 0.9726918075422, TNR: 0.9911550468262, PPV: 0.9777777777777, NPV: 0.9890965732087, FNR: 0.0273081924577, FPR: 0.0088449531737, FDR: 0.0222222222222, FOR: 0.0109034267912, F1S: 0.9752281616688, }, \
 {name: "normal", TP: 709, FN: 17, FP: 10, TN: 1955, TPR: 0.9765840220385, TNR: 0.9949109414758, PPV: 0.9860917941585, NPV: 0.9913793103448, FNR: 0.0234159779614, FPR: 0.0050890585241, FDR: 0.0139082058414, FOR: 0.0086206896551, F1S: 0.9813148788927, }, \
 {name: "static", TP: 445, FN: 8, FP: 22, TN: 2216, TPR: 0.9823399558498, TNR: 0.9901697944593, PPV: 0.9528907922912, NPV: 0.9964028776978, FNR: 0.0176600441501, FPR: 0.0098302055406, FDR: 0.0471092077087, FOR: 0.0035971223021, F1S: 0.9673913043478, }, \
 {name: "Sitting", TP: 76, FN: 3, FP: 13, TN: 2599, TPR: 0.9620253164556, TNR: 0.9950229709035, PPV: 0.8539325842696, NPV: 0.9988470407378, FNR: 0.0379746835443, FPR: 0.0049770290964, FDR: 0.1460674157303, FOR: 0.0011529592621, F1S: 0.9047619047619, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 92.665 %
* (F1S) F1 Score 92.672 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              130              142               15              148               83
* (FN) False Negative or Incorrect Negative Prediction                0                8                9                1               12               11
* (FP) False Positive or Incorrect Positive Prediction                0                4               12                2               16                7
* (TN) True Negative or Correct Negative Prediction                 559              417              396              541              383              458
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          94.20 %          94.04 %          93.75 %          92.50 %          88.30 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.05 %          97.06 %          99.63 %          95.99 %          98.49 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          97.01 %          92.21 %          88.24 %          90.24 %          92.22 %
* (NPV) Negative Predictive Value                              100.00 %          98.12 %          97.78 %          99.82 %          96.96 %          97.65 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           5.80 %           5.96 %           6.25 %           7.50 %          11.70 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.95 %           2.94 %           0.37 %           4.01 %           1.51 %
* (FDR) False Discovery Rate                                   100.00 %           2.99 %           7.79 %          11.76 %           9.76 %           7.78 %
* (FOR) False Omission Rate                                      0.00 %           1.88 %           2.22 %           0.18 %           3.04 %           2.35 %
* (F1S) F1 Score                                               100.00 %          95.59 %          93.11 %          90.91 %          91.36 %          90.22 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9266547406082289 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9267221561218627 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 559, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 130, FN: 8, FP: 4, TN: 417, TPR: 0.9420289855072, TNR: 0.9904988123515, PPV: 0.9701492537313, NPV: 0.9811764705882, FNR: 0.0579710144927, FPR: 0.0095011876484, FDR: 0.0298507462686, FOR: 0.0188235294117, F1S: 0.9558823529411, }, \
 {name: "Squatting", TP: 148, FN: 12, FP: 16, TN: 383, TPR: 0.925, TNR: 0.9598997493734, PPV: 0.9024390243902, NPV: 0.9696202531645, FNR: 0.075, FPR: 0.0401002506265, FDR: 0.0975609756097, FOR: 0.0303797468354, F1S: 0.9135802469135, }, \
 {name: "normal", TP: 142, FN: 9, FP: 12, TN: 396, TPR: 0.9403973509933, TNR: 0.9705882352941, PPV: 0.9220779220779, NPV: 0.9777777777777, FNR: 0.0596026490066, FPR: 0.0294117647058, FDR: 0.0779220779220, FOR: 0.0222222222222, F1S: 0.9311475409836, }, \
 {name: "static", TP: 83, FN: 11, FP: 7, TN: 458, TPR: 0.8829787234042, TNR: 0.9849462365591, PPV: 0.9222222222222, NPV: 0.9765458422174, FNR: 0.1170212765957, FPR: 0.0150537634408, FDR: 0.0777777777777, FOR: 0.0234541577825, F1S: 0.9021739130434, }, \
 {name: "Sitting", TP: 15, FN: 1, FP: 2, TN: 541, TPR: 0.9375, TNR: 0.9963167587476, PPV: 0.8823529411764, NPV: 0.9981549815498, FNR: 0.0625, FPR: 0.0036832412523, FDR: 0.1176470588235, FOR: 0.0018450184501, F1S: 0.9090909090909, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xfc, 0xcf, 0x0d, 0x9c, 0xf6, 0xd9, 0x57, 0x44, 0xa8, 0x7f, 0xb8, 0xe1, 0x7c, 0x90, 0x97, 0xe3}

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

#define IMAI_KEY_MAX (71)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */

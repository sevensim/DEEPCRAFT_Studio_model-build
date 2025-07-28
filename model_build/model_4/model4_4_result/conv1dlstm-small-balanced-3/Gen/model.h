/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/24/2025 12:43:20 UTC. Any changes will be lost.
* 
* Model ID  62ece1d3-f1ad-49ed-98ce-9e30edcf808c
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
* (ACC) Accuracy 95.329 %
* (F1S) F1 Score 95.358 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              138              149               15              154               95
* (FN) False Negative or Incorrect Negative Prediction                0                5                7                2               11                2
* (FP) False Positive or Incorrect Positive Prediction                0                2                5                4                7                9
* (TN) True Negative or Correct Negative Prediction                 578              433              417              557              406              472
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          96.50 %          95.51 %          88.24 %          93.33 %          97.94 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.54 %          98.82 %          99.29 %          98.31 %          98.13 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          98.57 %          96.75 %          78.95 %          95.65 %          91.35 %
* (NPV) Negative Predictive Value                              100.00 %          98.86 %          98.35 %          99.64 %          97.36 %          99.58 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           3.50 %           4.49 %          11.76 %           6.67 %           2.06 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.46 %           1.18 %           0.71 %           1.69 %           1.87 %
* (FDR) False Discovery Rate                                   100.00 %           1.43 %           3.25 %          21.05 %           4.35 %           8.65 %
* (FOR) False Omission Rate                                      0.00 %           1.14 %           1.65 %           0.36 %           2.64 %           0.42 %
* (F1S) F1 Score                                               100.00 %          97.53 %          96.13 %          83.33 %          94.48 %          94.53 %
*/


#define IMAI_TEST_AVG_ACC 0.9532871972318339 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9535847186097811 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 578, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 138, FN: 5, FP: 2, TN: 433, TPR: 0.9650349650349, TNR: 0.9954022988505, PPV: 0.9857142857142, NPV: 0.9885844748858, FNR: 0.0349650349650, FPR: 0.0045977011494, FDR: 0.0142857142857, FOR: 0.0114155251141, F1S: 0.9752650176678, }, \
 {name: "Squatting", TP: 154, FN: 11, FP: 7, TN: 406, TPR: 0.9333333333333, TNR: 0.9830508474576, PPV: 0.9565217391304, NPV: 0.9736211031175, FNR: 0.0666666666666, FPR: 0.0169491525423, FDR: 0.0434782608695, FOR: 0.0263788968824, F1S: 0.9447852760736, }, \
 {name: "normal", TP: 149, FN: 7, FP: 5, TN: 417, TPR: 0.9551282051282, TNR: 0.9881516587677, PPV: 0.9675324675324, NPV: 0.9834905660377, FNR: 0.0448717948717, FPR: 0.0118483412322, FDR: 0.0324675324675, FOR: 0.0165094339622, F1S: 0.9612903225806, }, \
 {name: "static", TP: 95, FN: 2, FP: 9, TN: 472, TPR: 0.9793814432989, TNR: 0.9812889812889, PPV: 0.9134615384615, NPV: 0.9957805907172, FNR: 0.0206185567010, FPR: 0.0187110187110, FDR: 0.0865384615384, FOR: 0.0042194092827, F1S: 0.9452736318407, }, \
 {name: "Sitting", TP: 15, FN: 2, FP: 4, TN: 557, TPR: 0.8823529411764, TNR: 0.9928698752228, PPV: 0.7894736842105, NPV: 0.9964221824686, FNR: 0.1176470588235, FPR: 0.0071301247771, FDR: 0.2105263157894, FOR: 0.0035778175313, F1S: 0.8333333333333, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 99.740 %
* (F1S) F1 Score 99.740 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              664              721               79              767              453
* (FN) False Negative or Incorrect Negative Prediction                0                0                5                0                2                0
* (FP) False Positive or Incorrect Positive Prediction                0                0                1                0                0                6
* (TN) True Negative or Correct Negative Prediction                2691             2027             1964             2612             1922             2232
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %         100.00 %          99.31 %         100.00 %          99.74 %         100.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %         100.00 %          99.95 %         100.00 %         100.00 %          99.73 %
* (PPV) Positive Predictive Value or Precision                 100.00 %         100.00 %          99.86 %         100.00 %         100.00 %          98.69 %
* (NPV) Negative Predictive Value                              100.00 %         100.00 %          99.75 %         100.00 %          99.90 %         100.00 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           0.00 %           0.69 %           0.00 %           0.26 %           0.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.00 %           0.05 %           0.00 %           0.00 %           0.27 %
* (FDR) False Discovery Rate                                   100.00 %           0.00 %           0.14 %           0.00 %           0.00 %           1.31 %
* (FOR) False Omission Rate                                      0.00 %           0.00 %           0.25 %           0.00 %           0.10 %           0.00 %
* (F1S) F1 Score                                               100.00 %         100.00 %          99.59 %         100.00 %          99.87 %          99.34 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9973987365291713 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9974025074195296 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2691, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 664, FN: 0, FP: 0, TN: 2027, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
 {name: "Squatting", TP: 767, FN: 2, FP: 0, TN: 1922, TPR: 0.9973992197659, TNR: 1, PPV: 1, NPV: 0.9989604989604, FNR: 0.0026007802340, FPR: 0, FDR: 0, FOR: 0.0010395010395, F1S: 0.9986979166666, }, \
 {name: "normal", TP: 721, FN: 5, FP: 1, TN: 1964, TPR: 0.9931129476584, TNR: 0.9994910941475, PPV: 0.9986149584487, NPV: 0.9974606399187, FNR: 0.0068870523415, FPR: 0.0005089058524, FDR: 0.0013850415512, FOR: 0.0025393600812, F1S: 0.9958563535911, }, \
 {name: "static", TP: 453, FN: 0, FP: 6, TN: 2232, TPR: 1, TNR: 0.9973190348525, PPV: 0.9869281045751, NPV: 1, FNR: 0, FPR: 0.0026809651474, FDR: 0.0130718954248, FOR: 0, F1S: 0.9934210526315, }, \
 {name: "Sitting", TP: 79, FN: 0, FP: 0, TN: 2612, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 93.381 %
* (F1S) F1 Score 93.391 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              134              140               14              152               82
* (FN) False Negative or Incorrect Negative Prediction                0                4               11                2                8               12
* (FP) False Positive or Incorrect Positive Prediction                0                1                9                3               16                8
* (TN) True Negative or Correct Negative Prediction                 559              420              399              540              383              457
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.10 %          92.72 %          87.50 %          95.00 %          87.23 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.76 %          97.79 %          99.45 %          95.99 %          98.28 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.26 %          93.96 %          82.35 %          90.48 %          91.11 %
* (NPV) Negative Predictive Value                              100.00 %          99.06 %          97.32 %          99.63 %          97.95 %          97.44 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.90 %           7.28 %          12.50 %           5.00 %          12.77 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.24 %           2.21 %           0.55 %           4.01 %           1.72 %
* (FDR) False Discovery Rate                                   100.00 %           0.74 %           6.04 %          17.65 %           9.52 %           8.89 %
* (FOR) False Omission Rate                                      0.00 %           0.94 %           2.68 %           0.37 %           2.05 %           2.56 %
* (F1S) F1 Score                                               100.00 %          98.17 %          93.33 %          84.85 %          92.68 %          89.13 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9338103756708408 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9339121824760283 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 559, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 134, FN: 4, FP: 1, TN: 420, TPR: 0.9710144927536, TNR: 0.9976247030878, PPV: 0.9925925925925, NPV: 0.9905660377358, FNR: 0.0289855072463, FPR: 0.0023752969121, FDR: 0.0074074074074, FOR: 0.0094339622641, F1S: 0.9816849816849, }, \
 {name: "Squatting", TP: 152, FN: 8, FP: 16, TN: 383, TPR: 0.95, TNR: 0.9598997493734, PPV: 0.9047619047619, NPV: 0.9795396419437, FNR: 0.05, FPR: 0.0401002506265, FDR: 0.0952380952380, FOR: 0.0204603580562, F1S: 0.9268292682926, }, \
 {name: "normal", TP: 140, FN: 11, FP: 9, TN: 399, TPR: 0.9271523178807, TNR: 0.9779411764705, PPV: 0.9395973154362, NPV: 0.9731707317073, FNR: 0.0728476821192, FPR: 0.0220588235294, FDR: 0.0604026845637, FOR: 0.0268292682926, F1S: 0.9333333333333, }, \
 {name: "static", TP: 82, FN: 12, FP: 8, TN: 457, TPR: 0.8723404255319, TNR: 0.9827956989247, PPV: 0.9111111111111, NPV: 0.9744136460554, FNR: 0.1276595744680, FPR: 0.0172043010752, FDR: 0.0888888888888, FOR: 0.0255863539445, F1S: 0.8913043478260, }, \
 {name: "Sitting", TP: 14, FN: 2, FP: 3, TN: 540, TPR: 0.875, TNR: 0.9944751381215, PPV: 0.8235294117647, NPV: 0.9963099630996, FNR: 0.125, FPR: 0.0055248618784, FDR: 0.1764705882352, FOR: 0.0036900369003, F1S: 0.8484848484848, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xd3, 0xe1, 0xec, 0x62, 0xad, 0xf1, 0xed, 0x49, 0x98, 0xce, 0x9e, 0x30, 0xed, 0xcf, 0x80, 0x8c}

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

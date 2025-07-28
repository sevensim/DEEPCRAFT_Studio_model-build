/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/22/2025 08:34:47 UTC. Any changes will be lost.
* 
* Model ID  48d9d8a3-bd48-46f0-b61c-f13a5f16bfd7
* 
* Memory    Size                      Efficiency
* Buffers   9600 bytes (RAM)          80 %
* Readonly  36504 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-small-balanced-2
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
* Convolution 1D                 [30,32]         float      compute
*    filters = 32
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,32]
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
* (ACC) Accuracy 89.765 %
* (F1S) F1 Score 89.696 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              137              151               11              148               88
* (FN) False Negative or Incorrect Negative Prediction                0               10               10                6               23               12
* (FP) False Positive or Incorrect Positive Prediction                0               11               18                1               15               16
* (TN) True Negative or Correct Negative Prediction                 596              438              417              578              410              480
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          93.20 %          93.79 %          64.71 %          86.55 %          88.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          97.55 %          95.86 %          99.83 %          96.47 %          96.77 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          92.57 %          89.35 %          91.67 %          90.80 %          84.62 %
* (NPV) Negative Predictive Value                              100.00 %          97.77 %          97.66 %          98.97 %          94.69 %          97.56 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           6.80 %           6.21 %          35.29 %          13.45 %          12.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           2.45 %           4.14 %           0.17 %           3.53 %           3.23 %
* (FDR) False Discovery Rate                                   100.00 %           7.43 %          10.65 %           8.33 %           9.20 %          15.38 %
* (FOR) False Omission Rate                                      0.00 %           2.23 %           2.34 %           1.03 %           5.31 %           2.44 %
* (F1S) F1 Score                                               100.00 %          92.88 %          91.52 %          75.86 %          88.62 %          86.27 %
*/


#define IMAI_TEST_AVG_ACC 0.8976510067114094 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8969646960862971 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 596, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 137, FN: 10, FP: 11, TN: 438, TPR: 0.9319727891156, TNR: 0.9755011135857, PPV: 0.9256756756756, NPV: 0.9776785714285, FNR: 0.0680272108843, FPR: 0.0244988864142, FDR: 0.0743243243243, FOR: 0.0223214285714, F1S: 0.9288135593220, }, \
 {name: "Squatting", TP: 148, FN: 23, FP: 15, TN: 410, TPR: 0.8654970760233, TNR: 0.9647058823529, PPV: 0.9079754601226, NPV: 0.9468822170900, FNR: 0.1345029239766, FPR: 0.0352941176470, FDR: 0.0920245398773, FOR: 0.0531177829099, F1S: 0.8862275449101, }, \
 {name: "normal", TP: 151, FN: 10, FP: 18, TN: 417, TPR: 0.9378881987577, TNR: 0.9586206896551, PPV: 0.8934911242603, NPV: 0.9765807962529, FNR: 0.0621118012422, FPR: 0.0413793103448, FDR: 0.1065088757396, FOR: 0.0234192037470, F1S: 0.9151515151515, }, \
 {name: "static", TP: 88, FN: 12, FP: 16, TN: 480, TPR: 0.88, TNR: 0.9677419354838, PPV: 0.8461538461538, NPV: 0.9756097560975, FNR: 0.12, FPR: 0.0322580645161, FDR: 0.1538461538461, FOR: 0.0243902439024, F1S: 0.8627450980392, }, \
 {name: "Sitting", TP: 11, FN: 6, FP: 1, TN: 578, TPR: 0.6470588235294, TNR: 0.9982728842832, PPV: 0.9166666666666, NPV: 0.9897260273972, FNR: 0.3529411764705, FPR: 0.0017271157167, FDR: 0.0833333333333, FOR: 0.0102739726027, F1S: 0.7586206896551, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 96.775 %
* (F1S) F1 Score 96.773 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              647              705               73              716              440
* (FN) False Negative or Incorrect Negative Prediction                0               11               15                5               46                9
* (FP) False Positive or Incorrect Positive Prediction                0               19               24                3               10               30
* (TN) True Negative or Correct Negative Prediction                2667             1990             1923             2586             1895             2188
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          98.33 %          97.92 %          93.59 %          93.96 %          98.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.05 %          98.77 %          99.88 %          99.48 %          98.65 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          97.15 %          96.71 %          96.05 %          98.62 %          93.62 %
* (NPV) Negative Predictive Value                              100.00 %          99.45 %          99.23 %          99.81 %          97.63 %          99.59 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           1.67 %           2.08 %           6.41 %           6.04 %           2.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.95 %           1.23 %           0.12 %           0.52 %           1.35 %
* (FDR) False Discovery Rate                                   100.00 %           2.85 %           3.29 %           3.95 %           1.38 %           6.38 %
* (FOR) False Omission Rate                                      0.00 %           0.55 %           0.77 %           0.19 %           2.37 %           0.41 %
* (F1S) F1 Score                                               100.00 %          97.73 %          97.31 %          94.81 %          96.24 %          95.76 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9677540307461567 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9677270259027491 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2667, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 647, FN: 11, FP: 19, TN: 1990, TPR: 0.9832826747720, TNR: 0.9905425584868, PPV: 0.9714714714714, NPV: 0.9945027486256, FNR: 0.0167173252279, FPR: 0.0094574415131, FDR: 0.0285285285285, FOR: 0.0054972513743, F1S: 0.9773413897280, }, \
 {name: "Squatting", TP: 716, FN: 46, FP: 10, TN: 1895, TPR: 0.9396325459317, TNR: 0.9947506561679, PPV: 0.9862258953168, NPV: 0.9763008758371, FNR: 0.0603674540682, FPR: 0.0052493438320, FDR: 0.0137741046831, FOR: 0.0236991241628, F1S: 0.9623655913978, }, \
 {name: "normal", TP: 705, FN: 15, FP: 24, TN: 1923, TPR: 0.9791666666666, TNR: 0.9876733436055, PPV: 0.9670781893004, NPV: 0.9922600619195, FNR: 0.0208333333333, FPR: 0.0123266563944, FDR: 0.0329218106995, FOR: 0.0077399380804, F1S: 0.9730848861283, }, \
 {name: "static", TP: 440, FN: 9, FP: 30, TN: 2188, TPR: 0.9799554565701, TNR: 0.9864743011722, PPV: 0.9361702127659, NPV: 0.9959035047792, FNR: 0.0200445434298, FPR: 0.0135256988277, FDR: 0.0638297872340, FOR: 0.0040964952207, F1S: 0.9575625680087, }, \
 {name: "Sitting", TP: 73, FN: 5, FP: 3, TN: 2586, TPR: 0.9358974358974, TNR: 0.9988412514484, PPV: 0.9605263157894, NPV: 0.9980702431493, FNR: 0.0641025641025, FPR: 0.0011587485515, FDR: 0.0394736842105, FOR: 0.0019297568506, F1S: 0.9480519480519, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 91.681 %
* (F1S) F1 Score 91.664 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              128              145               14              140               91
* (FN) False Negative or Incorrect Negative Prediction                0               12                7                3               21                4
* (FP) False Positive or Incorrect Positive Prediction                0                7               13                1               11               15
* (TN) True Negative or Correct Negative Prediction                 565              418              400              547              393              455
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          91.43 %          95.39 %          82.35 %          86.96 %          95.79 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.35 %          96.85 %          99.82 %          97.28 %          96.81 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          94.81 %          91.77 %          93.33 %          92.72 %          85.85 %
* (NPV) Negative Predictive Value                              100.00 %          97.21 %          98.28 %          99.45 %          94.93 %          99.13 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           8.57 %           4.61 %          17.65 %          13.04 %           4.21 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.65 %           3.15 %           0.18 %           2.72 %           3.19 %
* (FDR) False Discovery Rate                                   100.00 %           5.19 %           8.23 %           6.67 %           7.28 %          14.15 %
* (FOR) False Omission Rate                                      0.00 %           2.79 %           1.72 %           0.55 %           5.07 %           0.87 %
* (F1S) F1 Score                                               100.00 %          93.09 %          93.55 %          87.50 %          89.74 %          90.55 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9168141592920354 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9166423028301972 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 565, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 128, FN: 12, FP: 7, TN: 418, TPR: 0.9142857142857, TNR: 0.9835294117647, PPV: 0.9481481481481, NPV: 0.9720930232558, FNR: 0.0857142857142, FPR: 0.0164705882352, FDR: 0.0518518518518, FOR: 0.0279069767441, F1S: 0.9309090909090, }, \
 {name: "Squatting", TP: 140, FN: 21, FP: 11, TN: 393, TPR: 0.8695652173913, TNR: 0.9727722772277, PPV: 0.9271523178807, NPV: 0.9492753623188, FNR: 0.1304347826086, FPR: 0.0272277227722, FDR: 0.0728476821192, FOR: 0.0507246376811, F1S: 0.8974358974358, }, \
 {name: "normal", TP: 145, FN: 7, FP: 13, TN: 400, TPR: 0.9539473684210, TNR: 0.9685230024213, PPV: 0.9177215189873, NPV: 0.9828009828009, FNR: 0.0460526315789, FPR: 0.0314769975786, FDR: 0.0822784810126, FOR: 0.0171990171990, F1S: 0.9354838709677, }, \
 {name: "static", TP: 91, FN: 4, FP: 15, TN: 455, TPR: 0.9578947368421, TNR: 0.9680851063829, PPV: 0.8584905660377, NPV: 0.9912854030501, FNR: 0.0421052631578, FPR: 0.0319148936170, FDR: 0.1415094339622, FOR: 0.0087145969498, F1S: 0.9054726368159, }, \
 {name: "Sitting", TP: 14, FN: 3, FP: 1, TN: 547, TPR: 0.8235294117647, TNR: 0.9981751824817, PPV: 0.9333333333333, NPV: 0.9945454545454, FNR: 0.1764705882352, FPR: 0.0018248175182, FDR: 0.0666666666666, FOR: 0.0054545454545, F1S: 0.875, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xa3, 0xd8, 0xd9, 0x48, 0x48, 0xbd, 0xf0, 0x46, 0xb6, 0x1c, 0xf1, 0x3a, 0x5f, 0x16, 0xbf, 0xd7}

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

#define IMAI_KEY_MAX (26)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */

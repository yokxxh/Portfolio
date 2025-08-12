# Jupyter Notebooks

Various small scale projects related to machine learning and data science.

### Predicting House Prices using Regression

Trained multiple regression models to predict house prices from Miami Housing Dataset.
Models Trained: 
  - Linear 
  - Ridge
  - Lasso
  - Decision Tree Regressor
  - Random Forest Regressor
  - XGB Regressor

With RandomForest model, getting the best score metrics, R2 Score - 98.38%.

### Predicting Gallstone Disease

Trained multiple classification models to predict whether the features results in disease positive or negative.
Models Trained:
  - OnevsOne Classifier
  - Support Vector Classifier
  - KNeighbors Classifier
  - Random Forest Classifer
  - AdaBoost Classifier
  - Gradient Boosting Classifier

With Gradient Boosting Classifier performing above than other models, Accuracy - 85%.

### EDA & Data Visualization

- Performed Exploratory Data Analysis & Data Visualization on the titanic dataset.
- Imputed missing values, plotted correlation chart.
- Visualized the Distribution of various features by their survival.

### Clustering Evaluation for seeds dataset

Performed PCA, then segmented/clustered the data into three clusters.
Used models:

  - KMeans
  - DBSCAN
  - HDBSCAN
  - Agglomerative Clustering

With K-Means outperforming other models, with Davies-Bouldin Score: 70.6

### Image Classification with CNN

Built a Convolutional Neural Network to classify handwritten digits from the MNIST dataset with high accuracy.
Model has 2 sets of 2DConv layers, with dropout to avoid overfitting.
Attained Accuracy - 99%.

### Sentiment Analysis using Tensorflow

Built a basic tensorflow model to classify reviews based on their sentiment, processed the words, padded it into sequences,
and compiled the model and predicted the test set, attained accuracy - 87.63%
Added input to classify own reviews, based on our model.

global value

subscriber = rossubscriber('/chatter', @chatterCallback)
testData = zeros(1,100);

while 1
    testData = [testData(2:end) value.Data];
    plot(testData)
    grid on
    drawnow    
end
// app.js
document.addEventListener('DOMContentLoaded', function() {
    // Bin Status Overview Chart
    const binStatusChartCanvas = document.getElementById('binStatusChart');
    const binStatusChart = new Chart(binStatusChartCanvas, {
        type: 'line',
        data: {
            labels: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug'],
            datasets: [
                {
                    label: 'Full Bins',
                    data: [350, 400, 500, 450, 600,],
                    backgroundColor: 'rgba(75, 192, 192, 0.2)',
                    borderColor: 'rgba(75, 192, 192, 1)',
                    borderWidth: 1
                },
                // Add more datasets as needed
            ]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });

    // Bin Priority Chart
    const binPriorityChartCanvas = document.getElementById('binPriorityChart');
    const binPriorityChart = new Chart(binPriorityChartCanvas, {
        type: 'pie',
        data: {
            labels: ['Critical', 'High', 'Medium', 'Low'],
            datasets: [{
                data: [92, 119, 284, 125],
                backgroundColor: [
                    'rgba(255, 99, 132, 0.7)',
                    'rgba(255, 206, 86, 0.7)',
                    'rgba(54, 162, 235, 0.7)',
                    'rgba(75, 192, 192, 0.7)'
                ],
                borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(255, 206, 86, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(75, 192, 192, 1)'
                ],
                borderWidth: 1
            }]
        },
        options: {
            plugins: {
                legend: {
                    position: 'bottom'
                }
            }
        }
    });

    // Bin Activities Chart
    const binActivitiesChartCanvas = document.getElementById('binActivitiesChart');
    const binActivitiesChart = new Chart(binActivitiesChartCanvas, {
        type: 'bar',
        data: {
            labels: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug'],
            datasets: [
                {
                    label: 'Bin Emptied',
                    data: [450, 500, 600, 550, 700,0, 0, 0],
                    backgroundColor: 'rgba(75, 192, 192, 0.2)',
                    borderColor: 'rgba(75, 192, 192, 1)',
                    borderWidth: 1
                },
                // Add more datasets as needed
            ]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });
});